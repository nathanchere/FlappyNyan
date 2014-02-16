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