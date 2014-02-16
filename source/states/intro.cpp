#include <nds.h>
#include <stdio.h>
#include <../lib/gl2d.h>

#include "../h/bitmapfont.h"

#include "../h/gamestate.h"
#include "../h/gameengine.h"
#include "../h/gamestate.h"

#include "../h/global.h"

Intro Intro::_state;

void Intro::Init()
{			
    iprintf("Intro.Init\n");
}

void Intro::Dispose()
{
	
}

void Intro::Pause()
{
	
}

void Intro::Resume()
{

}

void Intro::HandleEvents(GameEngine* game)
{
	scanKeys();
	int held = keysHeld();
	if(held & KEY_A) game->ChangeState(Menu::Instance());
}



void Intro::Update(GameEngine* game) 
{
	
}

void Intro::Render(GameEngine* game) 
{	
	glBegin2D();        
	
	glBoxFilledGradient( 0, 0, 0, 0,
								 RGB15( 31,  0,  0 ),
								 RGB15(  0, 31,  0 ),
								 RGB15( 31,  0, 31 ),
								 RGB15(  0, 31, 31 )
                               );
			
	glColor( RGB15(0,31,31) );
		
	font_small.PrintCentered( 0, 100, "FLAPPY NYAN" );
	font_small.PrintCentered( 0, 120, "Press any button to start" );
	
	glEnd2D();
	glFlush(0);                    		
	
	swiWaitForVBlank();
}
