#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <vector>

using namespace std;

class GameState;

class GameEngine
{
public:

	void Init();

	void ChangeState(GameState* state);
	void PushState(GameState* state);
	void PopState();

	void HandleEvents();
	void Update();
	void Render();

	// TODO: screens?

private:
	vector<GameState*> states;
};

#endif
