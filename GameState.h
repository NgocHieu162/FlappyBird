#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"
#include "Pipe.h"
#include "Land.h"


class GameState : public State {
private:
	GameDataRef _data;
	sf::Clock clock;
	sf::Sprite _background;
	Pipe* pipe;
	Land* land;
		
public:
	GameState(GameDataRef data);
	void Init();
	void HandleInput();
	void Update(float dt);
	void Draw(float dt);
};
