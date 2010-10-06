/*************************************/
/*  menubar.cpp: Build the main menu */
/*************************************/

#include "fctsys.h"
#include "wx/wupdlock.h"

#include "appl_wxstruct.h"
#include "common.h"
#include "macros.h"
#include "gerbview.h"
#include "bitmaps.h"
#include "gerbview_id.h"
#include "hotkeys.h"


void WinEDA_GerberFrame::ReCreateMenuBar( void )
{
    wxWindowUpdateLocker dummy(this);

    wxMenuBar  *menuBar = GetMenuBar();

    /* Destroy the existing menu bar so it can be rebuilt.  This allows
     * language changes of the menu text on the fly. */
    if( menuBar )
        SetMenuBar( NULL );

    menuBar = new wxMenuBar();

    wxMenu* filesMenu = new wxMenu;
    filesMenu->Append( wxID_FILE, _( "Load Gerber File" ),
                       _( "Load a new Gerber file on the current layer. Previous data will be deleted" ),
                       FALSE );

    filesMenu->Append( ID_MENU_INC_LAYER_AND_APPEND_FILE,
                       _( "Inc Layer and load Gerber file" ),
                       _( "Increment layer number, and Load Gerber file" ),
                       FALSE );

    filesMenu->Append( ID_GERBVIEW_LOAD_DCODE_FILE, _( "Load DCodes" ),
                       _( "Load D-Codes File" ), FALSE );
#if 0   // TODO
    filesMenu->Append( ID_GERBVIEW_LOAD_DRILL_FILE, _( "Load EXCELLON Drill File" ),
                       _( "Load excellon drill file" ), FALSE );
#endif

    filesMenu->Append( ID_NEW_BOARD, _( "&Clear All" ),
                       _( "Clear all layers. All data will be deleted" ), FALSE );

    filesMenu->AppendSeparator();
    filesMenu->Append( ID_GERBVIEW_EXPORT_TO_PCBNEW,  _( "&Export to Pcbnew" ),
                       _( "Export data in pcbnew format" ), FALSE );


    filesMenu->AppendSeparator();

    filesMenu->Append( wxID_PRINT, _( "P&rint" ), _( "Print gerber" ) );
    filesMenu->Append( ID_GEN_PLOT, _( "Plot" ),
                       _( "Plotting in various formats" ) );

    filesMenu->AppendSeparator();
    filesMenu->Append( ID_EXIT, _( "E&xit" ), _( "Quit Gerbview" ) );

    wxGetApp().m_fileHistory.AddFilesToMenu( filesMenu );

    // Configuration and preferences:
    wxMenu* configmenu = new wxMenu;
    ADD_MENUITEM_WITH_HELP( configmenu, ID_CONFIG_REQ, _( "&File Ext" ),
                            _( "Set files extensions" ), config_xpm );
    ADD_MENUITEM_WITH_HELP( configmenu, ID_MENU_GERBVIEW_SHOW_HIDE_LAYERS_MANAGER_DIALOG,
                            _( "Hide &Layers Manager" ),
                            _( "Show/hide the layers manager toolbar" ),
                            layers_manager_xpm );
    ADD_MENUITEM_WITH_HELP( configmenu, ID_OPTIONS_SETUP, _( "&Options" ),
                            _( "Select general options" ), preference_xpm );

    ADD_MENUITEM_WITH_HELP( configmenu, ID_GERBVIEW_DISPLAY_OPTIONS_SETUP,
                            _( "Display" ),
                            _( "Select how items are displayed" ),
                            display_options_xpm );

    wxGetApp().AddMenuLanguageList( configmenu );

    AddHotkeyConfigMenu( configmenu );


    configmenu->AppendSeparator();
    ADD_MENUITEM_WITH_HELP( configmenu, ID_CONFIG_SAVE, _( "&Save Setup" ),
                            _( "Save application preferences" ),
                            save_setup_xpm );

    wxMenu* miscellaneous_menu = new wxMenu;
    ADD_MENUITEM_WITH_HELP( miscellaneous_menu, ID_GERBVIEW_SHOW_LIST_DCODES,
                            _( "&List DCodes" ),
                            _( "List and edit D-codes" ), show_dcodenumber_xpm );
    ADD_MENUITEM_WITH_HELP( miscellaneous_menu, ID_GERBVIEW_SHOW_SOURCE,
                            _( "&Show Source" ),
                            _( "Show source file for the current layer" ),
                            tools_xpm );
    miscellaneous_menu->AppendSeparator();
    ADD_MENUITEM_WITH_HELP( miscellaneous_menu, ID_GERBVIEW_GLOBAL_DELETE,
                            _( "&Delete Layer" ),
                            _( "Delete current layer" ), general_deletions_xpm );

    // Menu Help:
    wxMenu* helpMenu = new wxMenu;
    AddHelpVersionInfoMenuEntry( helpMenu );
    ADD_MENUITEM_WITH_HELP( helpMenu, ID_GENERAL_HELP, _( "&Contents" ),
                            _( "Open the gerbview manual" ), help_xpm );
    ADD_MENUITEM_WITH_HELP( helpMenu, ID_KICAD_ABOUT, _( "&About Gerbview" ),
                            _( "About gerbview gerber and drill viewer" ),
                            online_help_xpm );

    menuBar->Append( filesMenu, _( "&File" ) );
    menuBar->Append( configmenu, _( "&Preferences" ) );
    menuBar->Append( miscellaneous_menu, _( "&Miscellaneous" ) );

//TODO: one day...      menuBar->Append(drill_menu, _("&Drill"));
    menuBar->Append( helpMenu, _( "&Help" ) );

    // Associate the menu bar with the frame
    SetMenuBar( menuBar );
}