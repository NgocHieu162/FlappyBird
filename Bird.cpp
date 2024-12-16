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
	int g = 9.8 *25;
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

bool Bird::isAlive(std::vector<sf::Sprite>pipeSprites, Bubble& Bubbles,float dt)
{
	Collision collision;
	// add skill for bird
	std::vector<sf::Sprite> BubbleSprite = Bubbles.getSprite();
	for (int i = 0; i < BubbleSprite.size(); i++)
	{
		if (collision.checkCollision(birdSprite, BubbleSprite[i]))
		{
			skill = Bubbles.newSkillBird(birdSprite);
			BubbleSprite.erase(BubbleSprite.begin() + i);
			skill_duration = 0;
		}
	}
	Bubbles.setSprite(BubbleSprite);
	if (skill!= NORMAL)
	{
		if (skill_duration > SKILL_DURATION)
		{
			birdSprite.setColor(sf::Color::White);
			birdSprite.setScale(1, 1);
			skill = NORMAL;
			skill_duration = 0;
		}
		else
		{
			skill_duration += dt;
		}
	}

	if (skill == INVINCIBLE || skill ==INVISIBLE)
	{
		return true;
	}
	////f/*or (int i = 0; i < landSprites.size(); i++) {
	//	if (collision.checkCollision(birdSprite, landSprites[i])) {
	//		return false;
	//	}
	//}*/

	if (collision.getIsCollide() == false) {
		for (int i = 0; i < pipeSprites.size(); i++) {
			if (collision.checkCollision(birdSprite, pipeSprites[i])) {
				return false;
			}
		}
	}
	return true;
}	