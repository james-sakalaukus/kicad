/*********************************************************************/
/*  EESchema - edition des librairies: Edition des champs ( Fields ) */
/*********************************************************************/

#include "fctsys.h"
#include "gr_basic.h"
#include "common.h"
#include "class_drawpanel.h"
#include "confirm.h"

#include "program.h"
#include "general.h"
#include "libcmp.h"
#include "protos.h"
#include "libeditfrm.h"
#include "class_library.h"


/* Routines locales */
static void ShowMoveField( WinEDA_DrawPanel* panel, wxDC* DC, bool erase );


/* Variables locales */
extern int     m_unit;
static wxPoint StartCursor, LastTextPosition;


static void ExitMoveField( WinEDA_DrawPanel* Panel, wxDC* DC )
{
    Panel->ManageCurseur = NULL;
    Panel->ForceCloseManageCurseur = NULL;

    WinEDA_LibeditFrame* parent = ( WinEDA_LibeditFrame* ) Panel->GetParent();

    if( parent == NULL )
        return;

    LIB_DRAW_ITEM* item = parent->GetDrawItem();

    if( item == NULL )
        return;

    wxPoint curpos = Panel->GetScreen()->m_Curseur;

    Panel->GetScreen()->m_Curseur = StartCursor;
    ShowMoveField( Panel, DC, TRUE );
    Panel->GetScreen()->m_Curseur = curpos;
    item->m_Flags = 0;
    parent->SetDrawItem( NULL );
}


/*
 * Initialise le deplacement d'un champ ( ref ou Name )
 */
void WinEDA_LibeditFrame::StartMoveField( wxDC* DC, LibDrawField* field )
{
    wxPoint startPos;

    if( ( m_component == NULL ) || ( field == NULL ) )
        return;

    m_drawItem  = field;
    LastTextPosition = field->m_Pos;
    m_drawItem->m_Flags |= IS_MOVED;

    startPos.x = LastTextPosition.x;
    startPos.y = -LastTextPosition.y;
    DrawPanel->CursorOff( DC );
    GetScreen()->m_Curseur = startPos;
    DrawPanel->MouseToCursorSchema();

    DrawPanel->ManageCurseur = ShowMoveField;
    DrawPanel->ForceCloseManageCurseur = ExitMoveField;
    DrawPanel->ManageCurseur( DrawPanel, DC, TRUE );
    StartCursor = GetScreen()->m_Curseur;

    DrawPanel->CursorOn( DC );
}


/*****************************************************************/
/* Routine d'affichage du texte 'Field' en cours de deplacement. */
/*  Routine normalement attachee au curseur                     */
/*****************************************************************/
static void ShowMoveField( WinEDA_DrawPanel* panel, wxDC* DC, bool erase )
{
    WinEDA_LibeditFrame* parent = (WinEDA_LibeditFrame*) panel->GetParent();

    if( parent == NULL )
        return;

    LibDrawField* Field = (LibDrawField*) parent->GetDrawItem();

    if( Field == NULL )
        return;

    wxString text = Field->GetFullText( parent->GetUnit() );

    if( erase )
        Field->Draw( panel, DC, wxPoint( 0, 0 ), -1, g_XorMode, &text,
                     DefaultTransformMatrix );

    LastTextPosition.x = panel->GetScreen()->m_Curseur.x;
    LastTextPosition.y = -panel->GetScreen()->m_Curseur.y;

    Field->m_Pos = LastTextPosition;
    Field->Draw( panel, DC, wxPoint( 0, 0 ), -1, g_XorMode, &text,
                 DefaultTransformMatrix );
}


void WinEDA_LibeditFrame::PlaceField( wxDC* DC, LibDrawField* Field )
{
    if( Field == NULL )
        return;

    Field->m_Flags = 0;
    Field->m_Pos.x = GetScreen()->m_Curseur.x;
    Field->m_Pos.y = -GetScreen()->m_Curseur.y;
    DrawPanel->CursorOff( DC );

    wxString fieldText = Field->GetFullText( m_unit );

    Field->Draw( DrawPanel, DC, wxPoint( 0, 0 ), -1, GR_DEFAULT_DRAWMODE,
                 &fieldText, DefaultTransformMatrix );

    DrawPanel->CursorOn( DC );
    GetScreen()->SetModify();
    DrawPanel->ManageCurseur = NULL;
    DrawPanel->ForceCloseManageCurseur = NULL;
    m_drawItem = NULL;
}


void WinEDA_LibeditFrame::EditField( wxDC* DC, LibDrawField* Field )
{
    wxString   Text;
    wxString   title;

    if( Field == NULL )
        return;

    switch( Field->m_FieldId )
    {
    case REFERENCE:
        title = wxT( "Reference:" );
        break;

    case VALUE:
        title = wxT( "Component Name / Value:" );
        break;

    default:
        break;
    }

    Text = Field->m_Text;

    /* FIXME: Use wxTextEntry dialog here and check for cancel button. */
    Get_Message( title, _( "Edit field" ), Text, this );
    Text.Replace( wxT( " " ), wxT( "_" ) );

    /* If the value field is changed, this is equivalent to creating a new
     * component from the old one.  Check for an existing library entry of
     * this "new" component and change the value only if there is no existing
     * entry with the same name.
     */
    if( Field->m_FieldId == VALUE && Text != Field->m_Text )
    {
        wxString msg;

        /* Test for an existing name in the current components alias list. */
        if( Field->GetParent()->m_AliasList.Index( Text, false ) != wxNOT_FOUND )
        {
            msg.Printf( _( "The field name <%s> is an existing alias of the \
component <%s>.\nPlease choose another name that does not conflict with any \
names in the alias list." ),
                        (const wxChar*) Text,
                        (const wxChar*) Field->GetParent()->GetName() );
            DisplayError( this, msg );
            return;
        }

        /* Test for an existing entry in the library to prevent duplicate
         * entry names.
         */
        if( m_library && m_library->FindEntry( Text ) != NULL )
        {
            msg.Printf( _( "The field name <%s> conflicts with an existing \
entry in the component library <%s>.\nPlease choose another name that does \
not conflict with any library entries." ),
                        (const wxChar*) Text,
                        (const wxChar*) m_library->GetName() );
            DisplayError( this, msg );
            return;
        }
    }

    wxString fieldText = Field->GetFullText( m_unit );

    Field->Draw( DrawPanel, DC, wxPoint( 0, 0 ), -1, g_XorMode, &fieldText,
                 DefaultTransformMatrix );

    if( !Text.IsEmpty() )
    {
        SaveCopyInUndoList( Field->GetParent() );
        Field->m_Text = Text;
    }
    else
    {
        DisplayError( this, _( "No new text: no change" ) );
    }

    fieldText = Field->GetFullText( m_unit );
    int drawMode = g_XorMode;

    if( Field->m_Flags == 0 )
        drawMode = GR_DEFAULT_DRAWMODE;

    Field->Draw( DrawPanel, DC, wxPoint( 0, 0 ), -1, drawMode, &fieldText,
                 DefaultTransformMatrix );

    GetScreen()->SetModify();
    UpdateAliasSelectList();
}


/*
 * Routine de modification de l'orientation ( Horiz ou Vert. ) du champ.
 * si un champ est en cours d'edition, modif de celui ci.
 * sinon Modif du champ pointe par la souris
 */
void WinEDA_LibeditFrame::RotateField( wxDC* DC, LibDrawField* Field )
{

    if( Field == NULL )
        return;

    GetScreen()->SetModify();
    DrawPanel->CursorOff( DC );
    GRSetDrawMode( DC, g_XorMode );

    wxString fieldText = Field->GetFullText( m_unit );

    Field->Draw( DrawPanel, DC, wxPoint( 0, 0 ), -1, g_XorMode, &fieldText,
                 DefaultTransformMatrix );

    if( Field->m_Orient )
        Field->m_Orient = 0;
    else
        Field->m_Orient = 1;

    int drawMode = g_XorMode;

    if( Field->m_Flags == 0 )
        drawMode = GR_DEFAULT_DRAWMODE;

    Field->Draw( DrawPanel, DC, wxPoint( 0, 0 ), -1, drawMode, &fieldText,
                 DefaultTransformMatrix );

    DrawPanel->CursorOn( DC );
}


/*
 * Locate the component fiels (ref, name or auxiliary fields) under the
 * mouse cursor
 * return:
 *   pointer on the field (or NULL )
 */
LibDrawField* WinEDA_LibeditFrame::LocateField( LIB_COMPONENT* LibEntry )
{
    wxPoint refpos = GetScreen()->m_Curseur;
    /* Test reference */
    if( LibEntry->m_Name.HitTest( refpos ) )
        return &LibEntry->m_Name;

    /* Test Prefix */
    if( LibEntry->m_Prefix.HitTest( refpos ) )
        return &LibEntry->m_Prefix;

    /* Test others fields */
    for( LibDrawField* field = LibEntry->m_Fields; field != NULL;
         field = field->Next() )
    {
        if( field->m_Text.IsEmpty() )
            continue;

        if( field->HitTest( refpos ) )
            return field;
    }

    return NULL;
}


LIB_DRAW_ITEM* WinEDA_LibeditFrame::LocateItemUsingCursor()
{
    LIB_DRAW_ITEM* DrawEntry = m_drawItem;

    if( m_component == NULL )
        return NULL;

    if( ( DrawEntry == NULL ) || ( DrawEntry->m_Flags == 0 ) )
    {
        DrawEntry = LocatePin( GetScreen()->m_Curseur, m_component,
                               m_unit, m_convert );
        if( DrawEntry == NULL )
        {
            DrawEntry = m_drawItem =
                LocateDrawItem( (SCH_SCREEN*) GetScreen(),
                                GetScreen()->m_MousePosition, m_component,
                                m_unit, m_convert, LOCATE_ALL_DRAW_ITEM );
        }
        if( DrawEntry == NULL )
        {
            DrawEntry = m_drawItem =
                LocateDrawItem( (SCH_SCREEN*) GetScreen(),
                                GetScreen()->m_Curseur, m_component,
                                m_unit, m_convert, LOCATE_ALL_DRAW_ITEM );
        }
        if( DrawEntry == NULL )
        {
            DrawEntry = m_drawItem =
                (LIB_DRAW_ITEM*) LocateField( m_component );
        }
    }

    return DrawEntry;
}
