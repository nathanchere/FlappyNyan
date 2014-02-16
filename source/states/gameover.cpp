#include <nds.h>
#include <stdio.h>
#include <../lib/gl2d.h>

#include "../h/gamestate.h"
#include "../h/gameengine.h"

#include "../h/global.h"

GameOver GameOver::_state;

void GameOver::Init()
{
	iprintf("GameOver.Init\n");
}

void GameOver::Dispose()
{
	
}

void GameOver::Pause()
{
	
}

void GameOver::Resume()
{

}

void GameOver::HandleEvents(GameEngine* game)
{
	
}

void GameOver::Update(GameEngine* game) 
{
	
}

void GameOver::Render(GameEngine* game) 
{
	glBegin2D();        
	
	glBoxFilledGradient( 0, 0, 255, 191,
								 RGB15( 31,  0,  0 ),
								 RGB15(  0, 31,  0 ),
								 RGB15( 31,  0, 31 ),
								 RGB15(  0, 31, 31 )
                               );
				
	glEnd2D();
	glFlush(0);                    		
	
	swiWaitForVBlank();
}
