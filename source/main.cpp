#include <ctime>
#include <nds.h>
#include <string.h>
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
	}

	return 0;
}