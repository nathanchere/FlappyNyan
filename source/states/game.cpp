#include <nds.h>
#include <stdio.h>
#include <../lib/gl2d.h>

#include "../h/gamestate.h"
#include "../h/gameengine.h"

#include "../h/global.h"

Game Game::_state;

void Game::Init()
{
	iprintf("Game.Init\n");
}

void Game::Dispose()
{
	
}

void Game::Pause()
{
	
}

void Game::Resume()
{

}

void Game::HandleEvents(GameEngine* game)
{
	
}

void Game::Update(GameEngine* game) 
{
	
}

void Game::Render(GameEngine* game) 
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
