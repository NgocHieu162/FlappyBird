#pragma once

#include "Game.h"

class  Collision {
private:
	bool isCollide = 0;
public:
	Collision();

	bool getIsCollide();
	bool checkCollision(sf::Sprite sprite1, sf::Sprite sprite2);
};