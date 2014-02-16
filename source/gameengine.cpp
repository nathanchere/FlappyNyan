#include <ctime>
#include <nds.h>
#include <string.h>
#include "h/gameengine.h"
#include "h/gamestate.h"

#include "h/global.h"

void GameEngine::Init()
{
	srand(clock());
	videoSetMode(MODE_5_3D);
	videoSetModeSub(MODE_0_2D);
	
	consoleInit( &bottomScreen, 0, BgType_Text4bpp, BgSize_T_256x256, 20, 0, false, false );	
	
	glScreen2D();
		
	// Init console font
	font_console.gfx = (u16*)fontTiles;
	font_console.pal = (u16*)fontPal;
	font_console.numChars = 95;
	font_console.numColors =  fontPalLen / 2;
	font_console.bpp = 4;
	font_console.asciiOffset = 32;
	font_console.convertSingleColor = false;			
	consoleSetFont(&bottomScreen, &font_console);
}

void GameEngine::ChangeState(GameState* state) 
{
	if ( !states.empty() ) {
		states.back()->Dispose();
		states.pop_back();
	}

	states.push_back(state);
	states.back()->Init();
}

void GameEngine::PushState(GameState* state)
{
	if ( !states.empty() ) {
		states.back()->Pause();
	}

	states.push_back(state);
	states.back()->Init();
}

void GameEngine::PopState()
{
	if ( !states.empty() ) {
		states.back()->Dispose();
		states.pop_back();
	}

	if (!states.empty()) states.back()->Resume();
}


void GameEngine::HandleEvents() 
{
	if (!states.empty()) states.back()->HandleEvents(this);
}

void GameEngine::Update() 
{
	if (!states.empty()) states.back()->Update(this);
}

void GameEngine::Render() 
{
	if (!states.empty()) states.back()->Render(this);
}
