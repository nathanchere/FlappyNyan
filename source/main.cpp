#include <ctime>
#include <cmath>
#include <nds.h>
#include <stdio.h>
#include <string.h>
#include <nf_lib.h>
#include "h/gameengine.h"
#include "h/gamestate.h"

int main() 
{	
	srand(clock());
	GameEngine game;
	game.Init();

	game.ChangeState(Intro::Instance());

	while (1)
	{
		game.HandleEvents();
		game.Update();
		game.Render();
		
		//swiWaitForVBlank();			
	}

	return 0;
}