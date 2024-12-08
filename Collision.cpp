#include "Collision.h"

Collision::Collision()
{
}

bool Collision::getIsCollide()
{
	return isCollide;
}

bool Collision::checkCollision(sf::Sprite sprite1, sf::Sprite sprite2)
{
	if (sprite1.getGlobalBounds().intersects(sprite2.getGlobalBounds()))
		return true;
	return false;
}