#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "gameengine.h"

class GameState
{
public:
	virtual void Init() = 0;
	virtual void Dispose() = 0;
	
	virtual void Pause() = 0;
	virtual void Resume() = 0;

	virtual void HandleEvents(GameEngine* game) = 0;
	virtual void Update(GameEngine* game) = 0;
	virtual void Render(GameEngine* game) = 0;

	void ChangeState(GameEngine* game, GameState* state) {
		game->ChangeState(state);
	}

protected:
	GameState() { }	
};

#include "gamestates/game.h"
#include "gamestates/gameover.h"
#include "gamestates/menu.h"
#include "gamestates/intro.h"

#endif