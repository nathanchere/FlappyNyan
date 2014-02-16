#include "h/gameengine.h"
#include "h/gamestate.h"

#include "h/global.h"

// Globals... ugh...

ConsoleFont font_console;
BitmapFont font_small;

PrintConsole topScreen;
PrintConsole bottomScreen;
glImage  FontImages[FONT_8X8_NUM_IMAGES];


int main() 
{	
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