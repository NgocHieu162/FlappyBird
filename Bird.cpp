#include "Bird.h"
#include "Definition.h"


Bird::Bird(GameDataRef data) : _data(data)
{
	isFlying = false;
	position = sf::Vector2<float>(_data->window.getSize().x / 2.0, _data->window.getSize().y / 2 - 200);
	velocity = sf::Vector2<float>(0, -acceleration.y * 18);
	acceleration = sf::Vector2<float>(0, GRAVITY);

	sf::Sprite sprite(_data->assets->getTexture("Bird_01"));
	sprite.setPosition(position.x, position.y);
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
		if (birdSprite.getTexture() == &_data->assets->getTexture("Bird_01"))
		{
			birdSprite.setTexture(_data->assets->getTexture("Bird_03"));
		}
		else if (birdSprite.getTexture() == &_data->assets->getTexture("Bird_02"))
		{
			birdSprite.setTexture(_data->assets->getTexture("Bird_03"));
		}
		else if (birdSprite.getTexture() == &_data->assets->getTexture("Bird_03"))
		{
			birdSprite.setTexture(_data->assets->getTexture("Bird_01"));
		
		}
		clock.restart();
	}
}

void Bird::moveBird(float dt)
{
	handler(dt);
	update();
}

void Bird::handler(float dt)
{	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		birdSprite.setRotation(-25);

		velocity.y = - acceleration.y * 18;
	}

	if (birdSprite.getRotation() != 90)
	{
		birdSprite.setRotation(birdSprite.getRotation() + 1);
	}
	else if (birdSprite.getRotation() == 90)
	{
		birdSprite.setTexture(_data->assets->getTexture("Bird_02"));
	}
}

void Bird::update()
{
	velocity.y += acceleration.y;
	position.y += velocity.y;
	if (position.y < 0)
	{
		position.y = 0;
	}
	else if (position.y > _data->window.getSize().y - birdSprite.getGlobalBounds().height)
	{
		position.y = _data->window.getSize().y - birdSprite.getGlobalBounds().height;
	}

	birdSprite.setPosition(position.x, position.y);
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


