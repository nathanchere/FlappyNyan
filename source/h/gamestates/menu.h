#ifndef GAMESTATE_MENU_H
#define GAMESTATE_MENU_H

#include "../gameengine.h"

class Menu : public GameState
{
public:
	void Init();
	void Dispose();

	void Pause();
	void Resume();

	void HandleEvents(GameEngine* game);
	void Update(GameEngine* game);
	void Render(GameEngine* game);	
	
	static Menu* Instance() {
		return &_state;
	}

protected:
	Menu() { }

private:
	static Menu _state;

};

#endif