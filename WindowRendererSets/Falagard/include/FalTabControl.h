/************************************************************************
    filename:   FalTabControl.h
    created:    Fri Jul 8 2005
    author:     Paul D Turner <paul@cegui.org.uk>
*************************************************************************/
/*************************************************************************
    Crazy Eddie's GUI System (http://www.cegui.org.uk)
    Copyright (C)2004 - 2005 Paul D Turner (paul@cegui.org.uk)
 
    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.
 
    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.
 
    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*************************************************************************/
#ifndef _FalTabControl_h_
#define _FalTabControl_h_

#include "FalModule.h"
#include "elements/CEGUITabControl.h"
#include "FalTabControlProperties.h"

#if defined(_MSC_VER)
#	pragma warning(push)
#	pragma warning(disable : 4251)
#endif

// Start of CEGUI namespace section
namespace CEGUI
{
    /*!
    \brief
        TabControl class for the FalagardBase module.

        This class requires LookNFeel to be assigned.  The LookNFeel should provide the following:

        States:
            - Enabled
            - Disabled

        Child Widgets:
            TabPane based widget with name suffix "__auto_TabPane__"
            optional: DefaultWindow to contain tab buttons with name suffix "__auto_TabPane__Buttons"

        Property initialiser definitions:
            - TabButtonType - specifies a TabButton based widget type to be
              created each time a new tab button is required.

    \note
        The current TabControl base class enforces a strict layout, so while
        imagery can be customised as desired, the general layout of the
        component widgets is, at least for the time being, fixed.
    */
    class FALAGARDBASE_API FalagardTabControl : public TabControlWindowRenderer
    {
    public:
        static const utf8   TypeName[];     //! type name for this widget.

        /*!
        \brief
            Constructor
        */
        FalagardTabControl(const String& type);

        const String& getTabButtonType() const;
        void setTabButtonType(const String& type);

        void render();

    protected:
        // overridden from TabControl base class.
        TabButton* createTabButton(const String& name) const;

        // data fields
        String  d_tabButtonType;

        // properties
        static FalagardTabControlProperties::TabButtonType d_tabButtonTypeProperty;
    };

} // End of  CEGUI namespace section


#if defined(_MSC_VER)
#	pragma warning(pop)
#endif

#endif  // end of guard _FalTabControl_h_