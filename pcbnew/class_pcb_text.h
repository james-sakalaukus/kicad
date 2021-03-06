/*
 * This program source code file is part of KiCad, a free EDA CAD application.
 *
 * Copyright (C) 2004 Jean-Pierre Charras, jaen-pierre.charras@gipsa-lab.inpg.com
 * Copyright (C) 1992-2011 KiCad Developers, see AUTHORS.txt for contributors.
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

/**
 * @file class_pcb_text.h
 * @brief TEXTE_PCB class definition.
 */

#ifndef CLASS_PCB_TEXT_H
#define CLASS_PCB_TEXT_H

#include <eda_text.h>
#include <class_board_item.h>
#include <PolyLine.h>


class LINE_READER;
class EDA_DRAW_PANEL;
class MSG_PANEL_ITEM;


class TEXTE_PCB : public BOARD_ITEM, public EDA_TEXT
{
public:
    TEXTE_PCB( BOARD_ITEM* parent );

    // Do not create a copy constructor.  The one generated by the compiler is adequate.

    ~TEXTE_PCB();

    const wxPoint& GetPosition() const          // was overload
    {
        return m_Pos;   // within EDA_TEXT
    }

    void SetPosition( const wxPoint& aPos )     // was overload
    {
        m_Pos = aPos;   // within EDA_TEXT
    }

    void Move( const wxPoint& aMoveVector )
    {
        m_Pos += aMoveVector;
    }

    void Rotate( const wxPoint& aRotCentre, double aAngle );

    void Flip( const wxPoint& aCentre );

    /* duplicate structure */
    void Copy( TEXTE_PCB* source );

    void Draw( EDA_DRAW_PANEL* panel, wxDC* DC,
               GR_DRAWMODE aDrawMode, const wxPoint& offset = ZeroOffset );

    void GetMsgPanelInfo( std::vector< MSG_PANEL_ITEM >& aList );

    bool HitTest( const wxPoint& aPosition )
    {
        return TextHitTest( aPosition );
    }

    bool HitTest( const EDA_RECT& aRect ) const
    {
        return TextHitTest( aRect );
    }

    wxString GetClass() const
    {
        return wxT( "PTEXT" );
    }

    /**
     * Function TransformShapeWithClearanceToPolygon
     * Convert the track shape to a closed polygon
     * Used in filling zones calculations
     * Circles and arcs are approximated by segments
     * @param aCornerBuffer = a buffer to store the polygon
     * @param aClearanceValue = the clearance around the pad
     * @param aCircleToSegmentsCount = the number of segments to approximate a circle
     * @param aCorrectionFactor = the correction to apply to circles radius to keep
     * clearance when the circle is approximated by segment bigger or equal
     * to the real clearance value (usually near from 1.0)
     */
    void TransformShapeWithClearanceToPolygon( std::vector <CPolyPt>& aCornerBuffer,
                                               int                    aClearanceValue,
                                               int                    aCircleToSegmentsCount,
                                               double                 aCorrectionFactor );

    wxString GetSelectMenuText() const;

    BITMAP_DEF GetMenuImage() const { return  add_text_xpm; }

    EDA_RECT GetBoundingBox() const { return GetTextBox(); };

    EDA_ITEM* Clone() const;

#if defined(DEBUG)
    void Show( int nestLevel, std::ostream& os ) const;
#endif
};

#endif  // #define CLASS_PCB_TEXT_H
