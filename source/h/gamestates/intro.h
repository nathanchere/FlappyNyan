#ifndef GAMESTATE_INTRO_H
#define GAMESTATE_INTRO_H

#include "../gameengine.h"

class Intro : public GameState
{
public:
	void Init();
	void Dispose();

	void Pause();
	void Resume();

	void HandleEvents(GameEngine* game);
	void Update(GameEngine* game);
	void Render(GameEngine* game);	
	
	static Intro* Instance() {
		return &_state;
	}

protected:
	Intro() { }

private:
	static Intro _state;

};

#endif