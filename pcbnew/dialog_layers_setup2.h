#ifndef __dialog_layers_setup2_h_
#define __dialog_layers_setup2_h_

/*
 * This program source code file is part of KICAD, a free EDA CAD application.
 *
 * Copyright (C) 2009 Isaac Marino Bavaresco, isaacbavaresco@yahoo.com.br
 * Copyright (C) 2009 SoftPLC Corporation, Dick Hollenbeck <dick@softplc.com>
 * Copyright (C) 2009 Kicad Developers, see change_log.txt for contributors.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, you may find one here:
 * http://www.gnu.org/licenses/old-licenses/gpl-2.0.html
 * or you may search the http://www.gnu.org website for the version 2 license,
 * or you may write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
 */


#include "dialog_layers_setup_base2.h"


class DIALOG_LAYERS_SETUP : public DIALOG_LAYERS_SETUP_BASE2
{
private:
    static wxPoint      s_LastPos;
    static wxSize       s_LastSize;

    WinEDA_PcbFrame*    m_Parent;

    int                 m_CopperLayerCount;
    int                 m_EnabledLayers;

    BOARD*              m_Pcb;

    void init();

    void setLayerCheckBox( int layer, bool isChecked );
    void setCopperLayerCheckBoxes( int copperCount );

    void showCopperChoice( int copperCount );
    void showBoardLayerNames();
    void showSelectedLayerCheckBoxes( int enableLayerMask );
    void showLayerTypes();
    void showPresets( int enabledLayerMask );

    /** return the selected layer mask within the UI checkboxes */
    int getUILayerMask();
    wxString getLayerName( int layer );
    int getLayerTypeIndex( int layer );


    void OnCancelButtonClick( wxCommandEvent& event );
    void OnOkButtonClick( wxCommandEvent& event );
    void OnCheckBox( wxCommandEvent& event );
    void DenyChangeCheckBox( wxCommandEvent& event );
    void OnPresetsChoice( wxCommandEvent& event );
    void OnCopperLayersChoice( wxCommandEvent& event );

    bool testLayerNames();


public:
    DIALOG_LAYERS_SETUP( WinEDA_PcbFrame* parent );
    ~DIALOG_LAYERS_SETUP( ) { };

    bool Show( bool show );     // overload stock function

};

#endif //__dialog_layers_setup2_h_
