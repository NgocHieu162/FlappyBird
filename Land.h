#pragma once
#include "SFML/Graphics.hpp"
#include "Game.h"
#include <vector>


class Land {
private:
	GameDataRef _data;
	std::vector<sf::Sprite> landSprites;
public:
	Land(GameDataRef data);

	std::vector<sf::Sprite>& getSprite();
	void moveLand(float dt);
	void drawLand();
};
