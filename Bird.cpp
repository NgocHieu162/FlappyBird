#include "Bird.h"
#include "Definition.h"

Bird::Bird(GameDataRef data) : _data(data)
{
	sf::Sprite sprite(_data->assets.getTexture("Bird"));
	this->birdSprite = sprite;

	sprite.setPosition(400, _data->window.getSize().y / 2);

}

sf::Sprite& Bird::getSprite()
{
	return birdSprite;
}

void Bird::moveBird(float dt)
{	
	int g = 9.8 *30;
	birdSprite.move(0, dt * g);
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		birdSprite.move(0, -1000 * dt);
	}
}

void Bird::drawBird()
{
	_data->window.draw(birdSprite);
}

void Bird::setSkill(int skillName)
{
	skill = skillName;
}

int Bird::getSkill()
{
	return skill;
}

float Bird::getSkillDuration()
{
	return skill_duration;
}

void Bird::setDuration(float dt)
{
	skill_duration += dt;
}
