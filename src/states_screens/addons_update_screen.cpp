//  SuperTuxKart - a fun racing game with go-kart
//  Copyright (C) 2010 Lucas Baudin
//
//  This program is free software; you can redistribute it and/or
//  modify it under the terms of the GNU General Public License
//  as published by the Free Software Foundation; either version 3
//  of the License, or (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

#ifdef ADDONS_MANAGER

#include "states_screens/addons_screen.hpp"
#include "states_screens/addons_update_screen.hpp"

/*pthread aren't supported natively by windows. Here a port: http://sourceware.org/pthreads-win32/ */
#  include <pthread.h>
#  include <sstream>


#include "addons/addons.hpp"
#include "addons/network.hpp"
#include "guiengine/widget.hpp"
#include "guiengine/widgets/label_widget.hpp"
#include "guiengine/widgets/ribbon_widget.hpp"
#include "guiengine/widgets.hpp"
#include "io/file_manager.hpp"
#include "states_screens/state_manager.hpp"
#include "states_screens/dialogs/addons_loading.hpp"

DEFINE_SCREEN_SINGLETON( AddonsUpdateScreen );

// ------------------------------------------------------------------------------------------------------

AddonsUpdateScreen::AddonsUpdateScreen() : Screen("addons_update.stkgui")
{
}

// ------------------------------------------------------------------------------------------------------

void AddonsUpdateScreen::loadedFromFile()
{
}
// ------------------------------------------------------------------------------------------------------

void AddonsUpdateScreen::eventCallback(GUIEngine::Widget* widget, const std::string& name, const int playerID)
{
    if (name == "back")
    {
        StateManager::get()->escapePressed();
    }
    else if (name == "category")
    {
        std::string selection = ((GUIEngine::RibbonWidget*)widget)->getSelectionIDString(PLAYER_ID_GAME_MASTER).c_str();
        
        if (selection == "tab_addons") StateManager::get()->replaceTopMostScreen(AddonsScreen::getInstance());
    }
}

// ------------------------------------------------------------------------------------------------------

void AddonsUpdateScreen::init()
{
}

// ------------------------------------------------------------------------------------------------------

void AddonsUpdateScreen::tearDown()
{
}
#endif
