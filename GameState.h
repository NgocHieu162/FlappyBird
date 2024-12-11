#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"
#include "Pipe.h"
#include "Land.h"
#include "Bird.h"
#include "Bubble.h"
#include "Collision.h"

class GameState : public State {
private:
	GameDataRef _data;
	sf::Clock clock;
	sf::Sprite _background;
	Pipe* pipe;
	Land* land;
	Bird* bird;
	Bubble* bubble;
	Collision collision;
public:
	GameState(GameDataRef data);
	void Init();
	void HandleInput();
	void Update(float dt);
	void Draw(float dt);
};
