#ifndef GAMESTATE_GAMEOVER_H
#define GAMESTATE_GAMEOVER_H

#include "../gameengine.h"

class GameOver : public GameState
{
public:
	void Init();
	void Dispose();

	void Pause();
	void Resume();

	void HandleEvents(GameEngine* game);
	void Update(GameEngine* game);
	void Render(GameEngine* game);	
	
	static GameOver* Instance() {
		return &_state;
	}

protected:
	GameOver() { }

private:
	static GameOver _state;

};

#endif