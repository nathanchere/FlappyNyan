#include <nds.h>
#include <stdio.h>
#include <../lib/gl2d.h>

#include "../h/gamestate.h"
#include "../h/gameengine.h"

#include "../h/global.h"

#define TIMER_SPEED (BUS_CLOCK/1024)

Intro Intro::_state;
uint timeElapsed;
uint ticks;
int color;

int minutes;

void Intro::Init()
{			
    iprintf("Intro.Init\n");
	timerStart(0, ClockDivider_1024, 0, NULL);
}

void Intro::Dispose()
{
	timerStop(0);
	iprintf("Intro.Dispose\n");
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
	ticks = timeElapsed / (BUS_CLOCK * 0.00001);
	
	if(ticks < 40)
		color = 0;
	else if(ticks <= 168)
	{
		int val = (ticks - 40) * 0.25;
		color = RGB15(val,val,val);
	}
	else if(ticks <= 300)
		color = RGB15(31,31,31);
	else if(ticks <= 428)
	{
		int val = 32 - ((ticks - 300) * 0.25);
		color = RGB15(val,val,val);
	}
	else if(ticks <= 450)
		color = 0;
	else game->ChangeState(Menu::Instance());
	
}

void Intro::Render(GameEngine* game) 
{	
	glBegin2D();        
	
	glBoxFilled( 0, 0, 259, 191,0);
	glColor(color);
		
	font_small.PrintCentered( 0, 100, "INTERESTING INTRO TEXT HERE..." );	
	
	glColor(RGB15(31,15,0));
	//font_small.PrintCentered( 0, 120, color);	
	//font_small.PrintCentered( 0, 140, ticks);	
	
	glEnd2D();
	glFlush(0);                    			
	swiWaitForVBlank();
}
