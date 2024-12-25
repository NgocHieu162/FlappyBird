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
	sf::Rect<float> rec = sprite2.getGlobalBounds();
	rec.width -= 10;
	rec.left += 5;
	if (sprite1.getGlobalBounds().intersects(rec))
		return true;
	return false;
}
