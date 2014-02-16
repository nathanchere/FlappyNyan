#include <ctime>
#include <cmath>
#include <nds.h>
#include <stdio.h>
#include <string.h>
//#include <gl2d.h>
#include "font.h"
#include "h/gameengine.h"
#include "h/gamestate.h"

int main() 
{	
	srand(clock());

	PrintConsole topScreen;
    PrintConsole bottomScreen;
	
	videoSetMode( MODE_5_3D );
	videoSetModeSub( MODE_0_2D  );
	
	//glScreen2D();
	
	consoleInit(&topScreen,1, BgType_Text4bpp, BgSize_T_256x256, 31,0, true, false);
	bgSetPriority(0, 1);

	vramSetBankI( VRAM_I_SUB_BG_0x06208000 );
	consoleInit( &bottomScreen, 0, BgType_Text4bpp, BgSize_T_256x256, 20, 0, false, false );
	ConsoleFont font;

	font.gfx = (u16*)fontTiles;
	font.pal = (u16*)fontPal;
	font.numChars = 95;
	font.numColors =  fontPalLen / 2;
	font.bpp = 4;
	font.asciiOffset = 32;
	font.convertSingleColor = false;
			
	consoleSetFont(&bottomScreen, &font);
	consoleSetFont(&topScreen, &font);	
	
	consoleSelect(&topScreen);
    iprintf("FlappyNyan");   
    consoleSelect(&bottomScreen);
    iprintf("Press any button or tap screen\nto begin");
	
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