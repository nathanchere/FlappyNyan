#include <nds.h>
#include <stdio.h>
#include <../lib/gl2d.h>

#include "font.h"
#include "font_8x8.h"
#include "../h/font_8x8_uv.h"

#include "../h/gamestate.h"
#include "../h/gameengine.h"
#include "../h/gamestate.h"

Intro Intro::_state;

ConsoleFont font;

PrintConsole topScreen;
PrintConsole bottomScreen;
glImage  FontImages[FONT_8X8_NUM_IMAGES];

void Intro::Init()
{	
	consoleInit(&topScreen,1, BgType_Text4bpp, BgSize_T_256x256, 31,0, true, false);
	bgSetPriority(0, 1);

	vramSetBankI( VRAM_I_SUB_BG_0x06208000 );
	consoleInit( &bottomScreen, 0, BgType_Text4bpp, BgSize_T_256x256, 20, 0, false, false );	
	

	font.gfx = (u16*)fontTiles;
	font.pal = (u16*)fontPal;
	font.numChars = 95;
	font.numColors =  fontPalLen / 2;
	font.bpp = 4;
	font.asciiOffset = 32;
	font.convertSingleColor = false;			
	consoleSetFont(&bottomScreen, &font);
	
	consoleSetFont(&topScreen, &font);	
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
	
}

void Intro::Update(GameEngine* game) 
{
	
}

void Intro::Render(GameEngine* game) 
{	
	glBegin2D();        
	// Do stuff
	glEnd2D();
	glFlush(0);                    	

	consoleSelect(&topScreen);	
    iprintf("FlappyNyan\n");   
    consoleSelect(&bottomScreen);
    iprintf("Press any button or tap screen\nto begin");
	
	swiWaitForVBlank();
}
