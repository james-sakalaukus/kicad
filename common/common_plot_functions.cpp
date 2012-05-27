/**
 * @file common_plot_functions.cpp
 * @brief Kicad: Common plotting Routines
 */

#include <fctsys.h>
#include <gr_basic.h>
#include <trigo.h>
#include <wxstruct.h>
#include <base_struct.h>
#include <common.h>
#include <plot_common.h>
#include <worksheet.h>
#include <macros.h>
#include <class_base_screen.h>
#include <drawtxt.h>
#include <class_title_block.h>

/* Plot sheet references
 * margin is in mils (1/1000 inch)
 */
void EDA_DRAW_FRAME::PlotWorkSheet( PLOTTER* plotter, BASE_SCREEN* screen )
{
#define WSTEXTSIZE      50   // Text size in mils

    const PAGE_INFO&    pageInfo = GetPageSettings();
    wxSize              pageSize = pageInfo.GetSizeMils();  // mils
    int                 xg, yg;

    wxPoint             pos, ref;
    EDA_COLOR_T         color;

    // Paper is sized in mils.  Here is a conversion factor to scale mils to internal units.
    int      iusPerMil = screen->MilsToIuScalar();

    wxString msg;
    wxSize   text_size;

#if defined(KICAD_GOST)
    wxSize   text_size2;
    wxSize   text_size3;
    wxSize   text_size1_5;
#else
    int      UpperLimit = VARIABLE_BLOCK_START_POSITION;
    bool     bold = false;
#endif

    bool     italic    = false;
    bool     thickness = 0;      //@todo : use current pen

    color = BLACK;
    plotter->SetColor( color );

    // Plot edge.
    ref.x = pageInfo.GetLeftMarginMils() * iusPerMil;
    ref.y = pageInfo.GetTopMarginMils()  * iusPerMil;

    xg    = ( pageSize.x - pageInfo.GetRightMarginMils() )  * iusPerMil;
    yg    = ( pageSize.y - pageInfo.GetBottomMarginMils() ) * iusPerMil;

#if defined(KICAD_GOST)
    plotter->MoveTo( ref );
    pos.x = xg;
    pos.y = ref.y;
    plotter->LineTo( pos );
    pos.x = xg;
    pos.y = yg;
    plotter->LineTo( pos );
    pos.x = ref.x;
    pos.y = yg;
    plotter->LineTo( pos );
    plotter->FinishTo( ref );

#else

    for( unsigned ii = 0; ii < 2; ii++ )
    {
        plotter->MoveTo( ref );

        pos.x = xg;
        pos.y = ref.y;
        plotter->LineTo( pos );

        pos.x = xg;
        pos.y = yg;
        plotter->LineTo( pos );

        pos.x = ref.x;
        pos.y = yg;
        plotter->LineTo( pos );

        plotter->FinishTo( ref );

        ref.x += GRID_REF_W * iusPerMil;
        ref.y += GRID_REF_W * iusPerMil;

        xg    -= GRID_REF_W * iusPerMil;
        yg    -= GRID_REF_W * iusPerMil;
    }

#endif

    text_size.x = WSTEXTSIZE * iusPerMil;
    text_size.y = WSTEXTSIZE * iusPerMil;

    // upper left corner in mils
    ref.x = pageInfo.GetLeftMarginMils();
    ref.y = pageInfo.GetTopMarginMils();

    // lower right corner in mils
    xg    = ( pageSize.x - pageInfo.GetRightMarginMils() );
    yg    = ( pageSize.y - pageInfo.GetBottomMarginMils() );

#if defined(KICAD_GOST)
    for( Ki_WorkSheetData* WsItem = &WS_Segm1_LU;
         WsItem != NULL;
         WsItem = WsItem->Pnext )
    {
        pos.x = ( ref.x - WsItem->m_Posx ) * iusPerMil;
        pos.y = ( yg - WsItem->m_Posy ) * iusPerMil;
        msg.Empty();
        switch( WsItem->m_Type )
        {
        case WS_CADRE:
            break;

        case WS_PODPIS_LU:
            if( WsItem->m_Legende )
                msg = WsItem->m_Legende;
            plotter->Text( pos, color,
                           msg, TEXT_ORIENT_VERT, text_size,
                           GR_TEXT_HJUSTIFY_CENTER, GR_TEXT_VJUSTIFY_BOTTOM,
                           thickness, italic, false );
            break;

        case WS_SEGMENT_LU:
            plotter->MoveTo( pos );
            pos.x = ( ref.x - WsItem->m_Endx ) * iusPerMil;
            pos.y = ( yg - WsItem->m_Endy ) * iusPerMil;
            plotter->FinishTo( pos );
            break;
        }
    }

    for( Ki_WorkSheetData* WsItem = &WS_Segm1_LT;
         WsItem != NULL;
         WsItem = WsItem->Pnext )
    {
        pos.x = ( ref.x + WsItem->m_Posx ) * iusPerMil;
        pos.y = ( ref.y + WsItem->m_Posy ) * iusPerMil;
        msg.Empty();
        switch( WsItem->m_Type )
        {
        case WS_SEGMENT_LT:
            plotter->MoveTo( pos );
            pos.x = ( ref.x + WsItem->m_Endx ) * iusPerMil;
            pos.y = ( ref.y + WsItem->m_Endy ) * iusPerMil;
            plotter->FinishTo( pos );
            break;
        }
    }

#else

    // Plot legend along the X axis.
    int ipas  = ( xg - ref.x ) / PAS_REF;
    int gxpas = ( xg - ref.x ) / ipas;
    for( int ii = ref.x + gxpas, jj = 1; ipas > 0; ii += gxpas, jj++, ipas-- )
    {
        msg.Empty();
        msg << jj;

        if( ii < xg - PAS_REF / 2 )
        {
            pos.x = ii * iusPerMil;
            pos.y = ref.y * iusPerMil;
            plotter->MoveTo( pos );
            pos.x = ii * iusPerMil;
            pos.y = ( ref.y + GRID_REF_W ) * iusPerMil;
            plotter->FinishTo( pos );
        }

        pos.x = ( ii - gxpas / 2 ) * iusPerMil;
        pos.y = ( ref.y + GRID_REF_W / 2 ) * iusPerMil;
        plotter->Text( pos, color,
                       msg, TEXT_ORIENT_HORIZ, text_size,
                       GR_TEXT_HJUSTIFY_CENTER, GR_TEXT_VJUSTIFY_CENTER,
                       thickness, italic, false );

        if( ii < xg - PAS_REF / 2 )
        {
            pos.x = ii * iusPerMil;
            pos.y = yg * iusPerMil;
            plotter->MoveTo( pos );
            pos.x = ii * iusPerMil;
            pos.y = (yg - GRID_REF_W) * iusPerMil;
            plotter->FinishTo( pos );
        }
        pos.x = ( ii - gxpas / 2 ) * iusPerMil;
        pos.y = ( yg - GRID_REF_W / 2 ) * iusPerMil;
        plotter->Text( pos, color,
                       msg, TEXT_ORIENT_HORIZ, text_size,
                       GR_TEXT_HJUSTIFY_CENTER, GR_TEXT_VJUSTIFY_CENTER,
                       thickness, italic, false );
    }

    // Plot legend along the Y axis.
    ipas  = ( yg - ref.y ) / PAS_REF;
    int gypas = (  yg - ref.y ) / ipas;
    for( int ii = ref.y + gypas, jj = 0; ipas > 0; ii += gypas, jj++, ipas-- )
    {
        if( jj < 26 )
            msg.Printf( wxT( "%c" ), jj + 'A' );
        else    // I hope 52 identifiers are enough...
            msg.Printf( wxT( "%c" ), 'a' + jj - 26 );
        if( ii < yg - PAS_REF / 2 )
        {
            pos.x = ref.x * iusPerMil;
            pos.y = ii * iusPerMil;
            plotter->MoveTo( pos );
            pos.x = ( ref.x + GRID_REF_W ) * iusPerMil;
            pos.y = ii * iusPerMil;
            plotter->FinishTo( pos );
        }
        pos.x = ( ref.x + GRID_REF_W / 2 ) * iusPerMil;
        pos.y = ( ii - gypas / 2 ) * iusPerMil;
        plotter->Text( pos, color,
                       msg, TEXT_ORIENT_HORIZ, text_size,
                       GR_TEXT_HJUSTIFY_CENTER, GR_TEXT_VJUSTIFY_CENTER,
                       thickness, italic, false );

        if( ii < yg - PAS_REF / 2 )
        {
            pos.x = xg * iusPerMil;
            pos.y = ii * iusPerMil;
            plotter->MoveTo( pos );
            pos.x = ( xg - GRID_REF_W ) * iusPerMil;
            pos.y = ii * iusPerMil;
            plotter->FinishTo( pos );
        }

        pos.x = ( xg - GRID_REF_W / 2 ) * iusPerMil;
        pos.y = ( ii - gypas / 2 ) * iusPerMil;
        plotter->Text( pos, color, msg, TEXT_ORIENT_HORIZ, text_size,
                       GR_TEXT_HJUSTIFY_CENTER, GR_TEXT_VJUSTIFY_CENTER,
                       thickness, italic, false );
    }

#endif

    // Plot the worksheet.
    text_size.x = SIZETEXT * iusPerMil;
    text_size.y = SIZETEXT * iusPerMil;

#if defined(KICAD_GOST)
    text_size2.x = SIZETEXT * iusPerMil * 2;
    text_size2.y = SIZETEXT * iusPerMil * 2;
    text_size3.x = SIZETEXT * iusPerMil * 3;
    text_size3.y = SIZETEXT * iusPerMil * 3;
    text_size1_5.x = SIZETEXT * iusPerMil * 1.5;
    text_size1_5.y = SIZETEXT * iusPerMil * 1.5;

    ref.x = pageSize.x - pageInfo.GetRightMarginMils();
    ref.y = pageSize.y - pageInfo.GetBottomMarginMils();

    if( screen->m_ScreenNumber == 1 )
    {
        for( Ki_WorkSheetData* WsItem = &WS_Date;
             WsItem != NULL;
             WsItem = WsItem->Pnext )
        {
            pos.x = ( ref.x - WsItem->m_Posx ) * iusPerMil;
            pos.y = ( ref.y - WsItem->m_Posy ) * iusPerMil;
            msg.Empty();

            switch( WsItem->m_Type )
            {
            case WS_DATE:
                break;

            case WS_REV:
                break;

            case WS_KICAD_VERSION:
                break;

            case WS_PODPIS:
                if( WsItem->m_Legende )
                    msg = WsItem->m_Legende;
                plotter->Text( pos, color,
                               msg, TEXT_ORIENT_HORIZ, text_size,
                               GR_TEXT_HJUSTIFY_LEFT, GR_TEXT_VJUSTIFY_CENTER,
                               thickness, italic, false );
                break;

            case WS_SIZESHEET:
                break;

            case WS_IDENTSHEET:
                if( WsItem->m_Legende )
                    msg = WsItem->m_Legende;
                if( screen->m_NumberOfScreens > 1 )
                    msg << screen->m_ScreenNumber;
                plotter->Text( pos, color,
                               msg, TEXT_ORIENT_HORIZ, text_size,
                               GR_TEXT_HJUSTIFY_LEFT, GR_TEXT_VJUSTIFY_CENTER,
                               thickness, italic, false );
                break;

            case WS_SHEETS:
                if( WsItem->m_Legende )
                    msg = WsItem->m_Legende;
            msg << screen->m_NumberOfScreens;
                plotter->Text( pos, color,
                               msg, TEXT_ORIENT_HORIZ, text_size,
                               GR_TEXT_HJUSTIFY_LEFT, GR_TEXT_VJUSTIFY_CENTER,
                               thickness, italic, false );
                break;

            case WS_COMPANY_NAME:
            msg = GetTitleBlock().GetCompany();
                if( !msg.IsEmpty() )
                {
                    plotter->Text( pos, color,
                                   msg, TEXT_ORIENT_HORIZ, text_size1_5,
                                   GR_TEXT_HJUSTIFY_CENTER, GR_TEXT_VJUSTIFY_CENTER,
                                   thickness, italic, false );
                }
                break;

            case WS_TITLE:
            msg = GetTitleBlock().GetTitle();
                if( !msg.IsEmpty() )
                {
                    plotter->Text( pos, color,
                                   msg, TEXT_ORIENT_HORIZ, text_size1_5,
                                   GR_TEXT_HJUSTIFY_CENTER, GR_TEXT_VJUSTIFY_CENTER,
                                   thickness, italic, false );
                }
                break;

            case WS_COMMENT1:
            msg = GetTitleBlock().GetComment1();
                if( !msg.IsEmpty() )
                {
                    plotter->Text( pos, color,
                                   msg, TEXT_ORIENT_HORIZ, text_size3,
                                   GR_TEXT_HJUSTIFY_CENTER, GR_TEXT_VJUSTIFY_CENTER,
                                   thickness, italic, false );
                    pos.x = (pageInfo.GetLeftMarginMils() + 1260) * iusPerMil;
                    pos.y = (pageInfo.GetTopMarginMils() + 270) * iusPerMil;
                    plotter->Text( pos, color,
                                   msg.GetData(), 1800, text_size2,
                                   GR_TEXT_HJUSTIFY_CENTER, GR_TEXT_VJUSTIFY_CENTER,
                                   thickness, italic, false );
                }
                break;

            case WS_COMMENT2:
            msg = GetTitleBlock().GetComment2();
                if( !msg.IsEmpty() )
                {
                    plotter->Text( pos, color,
                                   msg, TEXT_ORIENT_HORIZ, text_size,
                                   GR_TEXT_HJUSTIFY_LEFT, GR_TEXT_VJUSTIFY_CENTER,
                                   thickness, italic, false );
                }
                break;

            case WS_COMMENT3:
            msg = GetTitleBlock().GetComment3();
                if( !msg.IsEmpty() )
                {
                    plotter->Text( pos, color,
                                   msg, TEXT_ORIENT_HORIZ, text_size,
                                   GR_TEXT_HJUSTIFY_LEFT, GR_TEXT_VJUSTIFY_CENTER,
                                   thickness, italic, false );
                }
                break;

            case WS_COMMENT4:
            msg = GetTitleBlock().GetComment4();
                if( !msg.IsEmpty() )
                {
                    plotter->Text( pos, color,
                                   msg, TEXT_ORIENT_HORIZ, text_size,
                                   GR_TEXT_HJUSTIFY_LEFT, GR_TEXT_VJUSTIFY_CENTER,
                                   thickness, italic, false );
                }
                break;

            case WS_UPPER_SEGMENT:
            case WS_LEFT_SEGMENT:
            case WS_SEGMENT:
                plotter->MoveTo( pos );
                pos.x = ( ref.x - WsItem->m_Endx ) * iusPerMil;
                pos.y = ( ref.y - WsItem->m_Endy ) * iusPerMil;
                plotter->FinishTo( pos );
                break;
            }
        }
    }
    else
    {
        for( Ki_WorkSheetData* WsItem = &WS_CADRE_D;
             WsItem != NULL;
             WsItem = WsItem->Pnext )
        {
            pos.x = ( ref.x - WsItem->m_Posx ) * iusPerMil;
            pos.y = ( ref.y - WsItem->m_Posy ) * iusPerMil;
            msg.Empty();

            switch( WsItem->m_Type )
            {
            case WS_CADRE:
            // Begin list number > 1
            msg = GetTitleBlock().GetComment1();
                if( !msg.IsEmpty() )
                {
                    plotter->Text( pos, color,
                                   msg, TEXT_ORIENT_HORIZ, text_size3,
                                   GR_TEXT_HJUSTIFY_CENTER, GR_TEXT_VJUSTIFY_CENTER,
                                   thickness, italic, false );
                    pos.x = (pageInfo.GetLeftMarginMils() + 1260) * iusPerMil;
                    pos.y = (pageInfo.GetTopMarginMils() + 270) * iusPerMil;
                    plotter->Text( pos, color,
                                   msg, 1800, text_size2,
                                   GR_TEXT_HJUSTIFY_CENTER, GR_TEXT_VJUSTIFY_CENTER,
                                   thickness, italic, false );
                }
                break;

            case WS_PODPIS_D:
                if( WsItem->m_Legende )
                    msg = WsItem->m_Legende;
                plotter->Text( pos, color, msg, TEXT_ORIENT_HORIZ, text_size,
                               GR_TEXT_HJUSTIFY_LEFT, GR_TEXT_VJUSTIFY_CENTER,
                               thickness, italic, false );
                break;

            case WS_IDENTSHEET_D:
                if( WsItem->m_Legende )
                    msg = WsItem->m_Legende;
                msg << screen->m_ScreenNumber;
                plotter->Text( pos, color, msg, TEXT_ORIENT_HORIZ, text_size,
                               GR_TEXT_HJUSTIFY_LEFT, GR_TEXT_VJUSTIFY_CENTER,
                               thickness, italic, false );
                break;

            case WS_LEFT_SEGMENT_D:
            case WS_SEGMENT_D:
                plotter->MoveTo( pos );
                pos.x = ( ref.x - WsItem->m_Endx ) * iusPerMil;
                pos.y = ( ref.y - WsItem->m_Endy ) * iusPerMil;
                plotter->FinishTo( pos );
                break;
            }
        }
    }

#else

    ref.x = pageSize.x - GRID_REF_W - pageInfo.GetRightMarginMils();
    ref.y = pageSize.y - GRID_REF_W - pageInfo.GetBottomMarginMils();

    for( Ki_WorkSheetData* WsItem = &WS_Date;
         WsItem != NULL;
         WsItem = WsItem->Pnext )
    {
        pos.x = ( ref.x - WsItem->m_Posx ) * iusPerMil;
        pos.y = ( ref.y - WsItem->m_Posy ) * iusPerMil;
        bold  = false;
        if( WsItem->m_Legende )
            msg = WsItem->m_Legende;
        else
            msg.Empty();

        switch( WsItem->m_Type )
        {
        case WS_DATE:
            msg += GetTitleBlock().GetDate();
            bold = true;
            break;

        case WS_REV:
            msg += GetTitleBlock().GetRevision();
            bold = true;
            break;

        case WS_KICAD_VERSION:
            msg += g_ProductName;
            break;

        case WS_SIZESHEET:
            msg += pageInfo.GetType();
            break;

        case WS_IDENTSHEET:
            msg << screen->m_ScreenNumber << wxT( "/" ) <<
                screen->m_NumberOfScreens;
            break;

        case WS_FILENAME:
        {
            wxString fname, fext;
            wxFileName::SplitPath( screen->GetFileName(),
                                   (wxString*) NULL,
                                   &fname,
                                   &fext );
            msg << fname << wxT( "." ) << fext;
        }
        break;

        case WS_FULLSHEETNAME:
            msg += GetScreenDesc();
            break;

        case WS_COMPANY_NAME:
            msg += GetTitleBlock().GetCompany();
            if( !msg.IsEmpty() )
                UpperLimit = MAX( UpperLimit, WsItem->m_Posy + SIZETEXT );
            bold = true;
            break;

        case WS_TITLE:
            msg += GetTitleBlock().GetTitle();
            bold = true;
            break;

        case WS_COMMENT1:
            msg += GetTitleBlock().GetComment1();
            if( !msg.IsEmpty() )
                UpperLimit = MAX( UpperLimit, WsItem->m_Posy + SIZETEXT );
            break;

        case WS_COMMENT2:
            msg += GetTitleBlock().GetComment2();
            if( !msg.IsEmpty() )
                UpperLimit = MAX( UpperLimit, WsItem->m_Posy + SIZETEXT );
            break;

        case WS_COMMENT3:
            msg += GetTitleBlock().GetComment3();
            if( !msg.IsEmpty() )
                UpperLimit = MAX( UpperLimit, WsItem->m_Posy + SIZETEXT );
            break;

        case WS_COMMENT4:
            msg += GetTitleBlock().GetComment4();
            if( !msg.IsEmpty() )
                UpperLimit = MAX( UpperLimit, WsItem->m_Posy + SIZETEXT );
            break;

        case WS_UPPER_SEGMENT:
            if( UpperLimit == 0 )
                break;

        case WS_LEFT_SEGMENT:
            WS_MostUpperLine.m_Posy = WS_MostUpperLine.m_Endy
                = WS_MostLeftLine.m_Posy = UpperLimit;
            pos.y = (ref.y - WsItem->m_Posy) * iusPerMil;

        case WS_SEGMENT:
        {
            wxPoint auxpos;
            auxpos.x = ( ref.x - WsItem->m_Endx ) * iusPerMil;
            auxpos.y = ( ref.y - WsItem->m_Endy ) * iusPerMil;
            plotter->MoveTo( pos );
            plotter->FinishTo( auxpos );
        }
        break;
        }

        if( !msg.IsEmpty() )
        {
            plotter->Text( pos, color,
                           msg, TEXT_ORIENT_HORIZ, text_size,
                           GR_TEXT_HJUSTIFY_LEFT, GR_TEXT_VJUSTIFY_CENTER,
                           thickness, italic, bold );
        }
    }

#endif
}
