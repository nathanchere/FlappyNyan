#ifndef GAMESTATE_GAME_H
#define GAMESTATE_GAME_H

class Game : public GameState
{
public:
	void Init();
	void Dispose();

	void Pause();
	void Resume();

	void HandleEvents(GameEngine* game);
	void Update(GameEngine* game);
	void Render(GameEngine* game);	
	
	static Game* Instance() {
		return &_state;
	}

protected:
	Game() { }

private:
	static Game _state;

};

#endif