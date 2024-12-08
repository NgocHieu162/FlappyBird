#include "Bird.h"
#include "Definition.h"

Bird::Bird(GameDataRef data) : _data(data)
{
	sf::Sprite sprite(_data->assets.getTexture("Bird"));
	this->birdSprite = sprite;

	sprite.setPosition(_data->window.getSize().x + 100, _data->window.getSize().y / 2);

}

sf::Sprite& Bird::getSprite()
{
	return birdSprite;
}

void Bird::moveBird(float dt)
{
	birdSprite.move(0, 200 * dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		birdSprite.move(0, -1000 * dt);
	}
}

void Bird::drawBird()
{
	_data->window.draw(birdSprite);
}