#include <nds.h>
#include <stdio.h>
#include <../lib/gl2d.h>

#include "../h/gamestate.h"
#include "../h/gameengine.h"

#include "../h/global.h"

Menu Menu::_state;

void Menu::Init()
{			
    iprintf("Menu.Init\n");
}

void Menu::Dispose()
{
	
}

void Menu::Pause()
{
	
}

void Menu::Resume()
{

}

void Menu::HandleEvents(GameEngine* game)
{
	
}

void Menu::Update(GameEngine* game) 
{
	
}

void Menu::Render(GameEngine* game) 
{
	glBegin2D();        
	
	// backdrop
	glBoxFilled( 0, 0, 259, 191,0);
	
	// starfield
	
	// nyancat
	
	// press start
				
	glEnd2D();
	glFlush(0);                    		
	
	swiWaitForVBlank();
}
