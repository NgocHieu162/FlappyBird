#include "Bird.h"
#include "Definition.h"


Bird::Bird(GameDataRef data) : _data(data)
{
	sf::Sprite sprite(_data->assets.getTexture("Bird_01"));
	sprite.setPosition(_data->window.getSize().x/2.0, _data->window.getSize().y /2-200);
	this->birdSprite = sprite;

}

sf::Sprite& Bird::getSprite()
{
	return birdSprite;
}

void Bird::animateBird(sf::Clock clock)
{
	if (clock.getElapsedTime().asSeconds() > BIRD_ANIMATION_DURATION / 2)
	{ 
		if (birdSprite.getTexture() == &_data->assets.getTexture("Bird_01"))
		{
			birdSprite.setTexture(_data->assets.getTexture("Bird_03"));
		}
		else if (birdSprite.getTexture() == &_data->assets.getTexture("Bird_02"))
		{
			birdSprite.setTexture(_data->assets.getTexture("Bird_03"));
		}
		else if (birdSprite.getTexture() == &_data->assets.getTexture("Bird_03"))
		{
			birdSprite.setTexture(_data->assets.getTexture("Bird_01"));
		
		}
		clock.restart();
	}
}

void Bird::moveBird(float dt)
{	
	//set animation for bird
	birdSprite.move(0, GRAVITY * dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		birdSprite.setRotation(-25);
		birdSprite.move(0, -1000 * dt);

	}
	if (birdSprite.getRotation() != 90)
	{
		birdSprite.setRotation(birdSprite.getRotation() + 1);
	}
	else if (birdSprite.getRotation() == 90)
	{
		birdSprite.setTexture(_data->assets.getTexture("Bird_02"));
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

bool Bird::isAlive(std::vector<sf::Sprite>pipeSprites,std::vector<sf::Sprite> Lands, Bubble& Bubbles,float dt)
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
	if (collision.getIsCollide() == false)
	{
		for (int i = 0; i < Lands.size(); i++)
		{
			if (collision.checkCollision(birdSprite, Lands[i]))
			{
				return false;
			}
		}
	}

	if (collision.getIsCollide() == false) {
		for (int i = 0; i < pipeSprites.size(); i++) {
			if (collision.checkCollision(birdSprite, pipeSprites[i])) {
				return false;
			}
		}
	}
	return true;
}	


