#pragma once
#include "State.h"
#include "Game.h"

class GameOverState : public State
{
private:
	GameDataRef _data;
	sf::Sprite _background;
	sf::Sprite _gameOverTitle;
public:
	GameOverState(GameDataRef data);
	void Init();
	void HandleInput();
	void Update(float dt);
	void Draw(float dt);
};