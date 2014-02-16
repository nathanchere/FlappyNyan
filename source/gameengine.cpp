#include <ctime>
#include <nds.h>
#include <string.h>
#include "h/gameengine.h"
#include "h/gamestate.h"

void GameEngine::Init()
{
	srand(clock());
	videoSetMode(MODE_5_3D);
	videoSetModeSub(MODE_0_2D);
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
