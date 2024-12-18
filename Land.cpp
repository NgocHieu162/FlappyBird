#include "Land.h"
#include "Definition.h"

Land::Land(GameDataRef data) : _data(data)
{
	sf::Sprite sprite(_data->assets->getTexture("Land"));
	sf::Sprite sprite2(_data->assets->getTexture("Land"));

	sprite.setPosition(0, _data->window.getSize().y - sprite.getGlobalBounds().height);
	sprite2.setPosition(sprite.getGlobalBounds().width, _data->window.getSize().y - sprite.getGlobalBounds().height);

	landSprites.push_back(sprite);
	landSprites.push_back(sprite2);
}

std::vector<sf::Sprite> &Land::getSprite()
{
	return landSprites;
}

void Land::moveLand(float dt)
{
	for (int i = 0; i < landSprites.size(); i++) {
		float movement = PIPE_MOVEMENT_SPEED * dt;
		landSprites[i].move(-movement, 0);

		if (landSprites[i].getPosition().x < 0 - landSprites[i].getGlobalBounds().width) {
			landSprites[i].setPosition(_data->window.getSize().x, landSprites[i].getPosition().y);
		}
	}
}
void Land::drawLand()
{
	for (int i = 0; i < landSprites.size(); i++) {
		_data->window.draw(landSprites[i]);
	}
}

