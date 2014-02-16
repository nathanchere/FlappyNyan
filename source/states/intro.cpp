#include <nds.h>
#include <stdio.h>
#include <../lib/gl2d.h>

#include "../h/gamestate.h"
#include "../h/gameengine.h"

#include "../h/global.h"

#define TIMER_SPEED (BUS_CLOCK/1024)

Intro Intro::_state;
uint timeElapsed;

void Intro::Init()
{			
    iprintf("Intro.Init\n");
	timerStart(0, ClockDivider_1024, 0, NULL);
}

void Intro::Dispose()
{
	timerStop(0);
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
	timeElapsed += timerElapsed(0);
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
	font_small.PrintCentered( 0, 120, timeElapsed / (TIMER_SPEED * 0.01));
	
	glEnd2D();
	glFlush(0);                    		
	
	swiWaitForVBlank();
}
