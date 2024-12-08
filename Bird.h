#pragma once

#include "SFML/Graphics.hpp"
#include "Game.h"


class Bird {
private:
	GameDataRef _data;
	sf::Sprite birdSprite;
public:
	Bird(GameDataRef data);

	sf::Sprite& getSprite();
	void moveBird(float dt);
	void drawBird();
};
