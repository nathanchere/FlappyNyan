#include <nds.h>
#include <stdio.h>
#include <../lib/gl2d.h>

#include "../h/bitmapfont.h"
#include "font.h"
#include "font_8x8.h"
#include "../h/font_8x8_uv.h"

#include "../h/gamestate.h"
#include "../h/gameengine.h"
#include "../h/gamestate.h"

Menu Menu::_state;


void Menu::Init()
{			
    iprintf("Menu.ctor\n");
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
	
	glBoxFilledGradient( 0, 0, 122, 96,
								 RGB15( 31,  0,  0 ),
								 RGB15(  0, 31,  0 ),
								 RGB15( 31,  0, 31 ),
								 RGB15(  0, 31, 31 )
                               );
				
	glEnd2D();
	glFlush(0);                    		
	
	swiWaitForVBlank();
}
