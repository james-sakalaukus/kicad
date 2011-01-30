/***************************************************
 *  operations_on_item_lists.cpp
 * functions used in block commands, or undo/redo,
 * to move, mirror, delete, copy ... lists of schematic items
 */

#include "fctsys.h"
#include "appl_wxstruct.h"
#include "common.h"
#include "class_drawpanel.h"
#include "class_sch_screen.h"
#include "wxEeschemaStruct.h"

#include "general.h"
#include "protos.h"
#include "sch_bus_entry.h"
#include "sch_marker.h"
#include "sch_line.h"
#include "sch_no_connect.h"
#include "sch_polyline.h"
#include "sch_sheet.h"
#include "sch_component.h"
#include "sch_junction.h"


void SetSchItemParent( SCH_ITEM* Struct, SCH_SCREEN* Screen )
{
    switch( Struct->Type() )
    {
    case SCH_POLYLINE_T:
    case SCH_JUNCTION_T:
    case SCH_TEXT_T:
    case SCH_LABEL_T:
    case SCH_GLOBAL_LABEL_T:
    case SCH_HIERARCHICAL_LABEL_T:
    case SCH_COMPONENT_T:
    case SCH_LINE_T:
    case SCH_BUS_ENTRY_T:
    case SCH_SHEET_T:
    case SCH_MARKER_T:
    case SCH_NO_CONNECT_T:
        Struct->SetParent( Screen );
        break;

    case SCH_SHEET_LABEL_T:
        break;

    default:
        break;
    }
}


void RotateListOfItems( PICKED_ITEMS_LIST& aItemsList, wxPoint& rotationPoint )
{
    for( unsigned ii = 0; ii < aItemsList.GetCount(); ii++ )
    {
        SCH_ITEM* item = (SCH_ITEM*) aItemsList.GetPickedItem( ii );
        item->Rotate( rotationPoint );      // Place it in its new position.
        item->m_Flags = 0;
    }
}


void DeleteItemsInList( EDA_DRAW_PANEL* panel, PICKED_ITEMS_LIST& aItemsList );
void DuplicateItemsInList( SCH_SCREEN* screen, PICKED_ITEMS_LIST& aItemsList,
                           const wxPoint aMoveVector  );


void MirrorListOfItems( PICKED_ITEMS_LIST& aItemsList, wxPoint& aMirrorPoint )
{
    for( unsigned ii = 0; ii < aItemsList.GetCount(); ii++ )
    {
        SCH_ITEM* item = (SCH_ITEM*) aItemsList.GetPickedItem( ii );
        item->Mirror_Y( aMirrorPoint.x );      // Place it in its new position.
        item->m_Flags = 0;
    }
}


void Mirror_X_ListOfItems( PICKED_ITEMS_LIST& aItemsList, wxPoint& aMirrorPoint )
{
    for( unsigned ii = 0; ii < aItemsList.GetCount(); ii++ )
    {
        SCH_ITEM* item = (SCH_ITEM*) aItemsList.GetPickedItem( ii );
        item->Mirror_X( aMirrorPoint.y );      // Place it in its new position.
        item->m_Flags = 0;
    }
}


/**
 * Function MoveItemsInList
 *  Move a list of items to a given move vector
 * @param aItemsList = list of picked items
 * @param aMoveVector = the move vector value
 */
void MoveItemsInList( PICKED_ITEMS_LIST& aItemsList, const wxPoint aMoveVector )
{
    for( unsigned ii = 0; ii < aItemsList.GetCount(); ii++ )
    {
        SCH_ITEM* item = (SCH_ITEM*) aItemsList.GetPickedItem( ii );
        item->Move( aMoveVector );
    }
}


/**
 * Function DeleteItemsInList
 * delete schematic items in aItemsList
 * deleted items are put in undo list
 */
void DeleteItemsInList( EDA_DRAW_PANEL* panel, PICKED_ITEMS_LIST& aItemsList )
{
    SCH_SCREEN*        screen = (SCH_SCREEN*) panel->GetScreen();
    SCH_EDIT_FRAME*    frame  = (SCH_EDIT_FRAME*) panel->GetParent();
    PICKED_ITEMS_LIST  itemsList;
    ITEM_PICKER        itemWrapper;

    for( unsigned ii = 0; ii < aItemsList.GetCount(); ii++ )
    {
        SCH_ITEM* item = (SCH_ITEM*) aItemsList.GetPickedItem( ii );
        itemWrapper.m_PickedItem     = item;
        itemWrapper.m_UndoRedoStatus = UR_DELETED;

        if( item->Type() == SCH_SHEET_LABEL_T )
        {
            /* this item is depending on a sheet, and is not in global list */
            wxMessageBox( wxT( "DeleteItemsInList() err: unexpected SCH_SHEET_LABEL_T" ) );
        }
        else
        {
            screen->RemoveFromDrawList( item );

            /* Unlink the structure */
            item->SetNext( 0 );
            item->SetBack( 0 );
            itemsList.PushItem( itemWrapper );
        }
    }

    frame->SaveCopyInUndoList( itemsList, UR_DELETED );
}


/* Routine to delete an object from global drawing object list.
 *  Object is put in Undo list
 */
void DeleteStruct( EDA_DRAW_PANEL* panel, wxDC* DC, SCH_ITEM* DrawStruct )
{
    SCH_SCREEN*     screen = (SCH_SCREEN*) panel->GetScreen();
    SCH_EDIT_FRAME* frame  = (SCH_EDIT_FRAME*) panel->GetParent();

    if( !DrawStruct )
        return;

    if( DrawStruct->Type() == SCH_SHEET_LABEL_T )
    {
        /* This structure is attached to a node, and is not accessible by
         * the global list directly. */
        frame->SaveCopyInUndoList( (SCH_ITEM*)( (SCH_SHEET_PIN*) DrawStruct )->GetParent(),
                                   UR_CHANGED );
        frame->DeleteSheetLabel( DC ? true : false, (SCH_SHEET_PIN*) DrawStruct );
        return;
    }
    else
    {
        screen->RemoveFromDrawList( DrawStruct );

        panel->RefreshDrawingRect( DrawStruct->GetBoundingBox() );

        /* Unlink the structure */
        DrawStruct->SetNext( 0 );
        DrawStruct->SetBack( 0 );  // Only one struct -> no link

        frame->SaveCopyInUndoList( DrawStruct, UR_DELETED );
    }
}


/* Routine to copy a new entity of an object for each object in list and
 * reposition it.
 * Return the new created object list in aItemsList
 */
void DuplicateItemsInList( SCH_SCREEN* screen, PICKED_ITEMS_LIST& aItemsList,
                           const wxPoint aMoveVector )
{
    SCH_ITEM* newitem;

    if( aItemsList.GetCount() == 0 )
        return;

    for( unsigned ii = 0; ii < aItemsList.GetCount(); ii++ )
    {
        newitem = DuplicateStruct( (SCH_ITEM*) aItemsList.GetPickedItem( ii ) );
        aItemsList.SetPickedItem( newitem, ii );
        aItemsList.SetPickedItemStatus( UR_NEW, ii );
        {
            switch( newitem->Type() )
            {
            case SCH_POLYLINE_T:
            case SCH_JUNCTION_T:
            case SCH_LINE_T:
            case SCH_BUS_ENTRY_T:
            case SCH_TEXT_T:
            case SCH_LABEL_T:
            case SCH_GLOBAL_LABEL_T:
            case SCH_HIERARCHICAL_LABEL_T:
            case SCH_SHEET_LABEL_T:
            case SCH_MARKER_T:
            case SCH_NO_CONNECT_T:
            default:
                break;

            case SCH_SHEET_T:
            {
                SCH_SHEET* sheet = (SCH_SHEET*) newitem;
                sheet->m_TimeStamp = GetTimeStamp();
                sheet->SetSon( NULL );
                break;
            }

            case SCH_COMPONENT_T:
                ( (SCH_COMPONENT*) newitem )->m_TimeStamp = GetTimeStamp();
                ( (SCH_COMPONENT*) newitem )->ClearAnnotation( NULL );
                break;
            }

            SetSchItemParent( newitem, screen );
            newitem->SetNext( screen->GetDrawItems() );
            screen->SetDrawItems( newitem );
        }
    }

    MoveItemsInList( aItemsList, aMoveVector );
}


/**
 * Function DuplicateStruct
 *  Routine to create a new copy of given struct.
 *  The new object is not put in draw list (not linked)
 * @param aDrawStruct = the SCH_ITEM to duplicate
 * @param aClone (default = false)
 *     if true duplicate also some parameters that must be unique
 *     (timestamp and sheet name)
 *      aClone must be false. use true only is undo/redo duplications
 */
SCH_ITEM* DuplicateStruct( SCH_ITEM* aDrawStruct, bool aClone )
{
    wxCHECK_MSG( aDrawStruct != NULL, NULL,
                 wxT( "Cannot duplicate NULL schematic item!  Bad programmer." ) );

    SCH_ITEM* NewDrawStruct = aDrawStruct->Clone();

    if( aClone )
        NewDrawStruct->m_TimeStamp = aDrawStruct->m_TimeStamp;

    NewDrawStruct->m_Image = aDrawStruct;

    return NewDrawStruct;
}
