#include "Bubble.h"
#include "Definition.h"

Bubble::Bubble(GameDataRef _data) : _data(_data)
{
}

void Bubble::drawBubble()
{
	for (int i = 0; i < bubbleSprites.size(); i++) {
		_data->window.draw(bubbleSprites[i]);
	}
}

void Bubble::moveBubble(float dt)
{
	for (int i = 0; i < bubbleSprites.size(); i++) {
		if (bubbleSprites[i].getPosition().x < 0 - bubbleSprites[i].getGlobalBounds().width) {
			bubbleSprites.erase(bubbleSprites.begin() + i);
		}
		else {
			float movement = PIPE_MOVEMENT_SPEED * dt;
			bubbleSprites[i].move(-movement, 0);
		}
	}
}

std::vector<sf::Sprite>& Bubble::getSprite() 
{
	return bubbleSprites;
}

float Bubble::getSpawnTime()
{
	return bb_spawn_time;
}

void Bubble::setSpawnTime(float dt)
{
	bb_spawn_time += dt;
}

void Bubble::setSprite(std::vector<sf::Sprite> bubbleSprites)
{
	this->bubbleSprites = bubbleSprites;
}

void Bubble::setBubbleStrategy(BubbleStrategy* bubbleStrategy)
{
	this->bubbleStrategy = bubbleStrategy;
}

void InvincibleBubble::spawnBubble(GameDataRef _data, std::vector<sf::Sprite>& bubbleSprites)
{
	sf::Sprite sprite(_data->assets.getTexture("Bubble"));
	sprite.setPosition(_data->window.getSize().x, _data->window.getSize().y / 2);
	sprite.setColor(sf::Color::Red);
	bubbleSprites.push_back(sprite);
}

void TinyBubble::spawnBubble(GameDataRef _data, std::vector<sf::Sprite>& bubbleSprites)
{
	sf::Sprite sprite(_data->assets.getTexture("Bubble"));
	sprite.setPosition(_data->window.getSize().x, _data->window.getSize().y / 2);
	sprite.setColor(sf::Color::Green);
	sprite.setScale(0.5, 0.5);
	bubbleSprites.push_back(sprite);
}
void InvisibleBubble::spawnBubble(GameDataRef _data, std::vector<sf::Sprite>& bubbleSprites)
{
	sf::Sprite sprite(_data->assets.getTexture("Bubble"));
	sprite.setPosition(_data->window.getSize().x, _data->window.getSize().y / 2);
	sprite.setColor(sf::Color::Magenta);
	bubbleSprites.push_back(sprite);
}

void Bubble::SpawnRandomBubble()
{
	int random = rand() % 3;
	//bubbleStrategy = new TinyBubble();
	switch (random)
	{
	case 0:
		bubbleStrategy = new InvincibleBubble();
		break;
	case 1:
		bubbleStrategy = new TinyBubble();
		break;
	case 2:
		bubbleStrategy = new InvisibleBubble();
		break;
	}
	setBubbleStrategy(bubbleStrategy);

	bubbleStrategy->spawnBubble(_data, bubbleSprites);
}

int InvincibleBubble::newSkillBird(sf::Sprite& BirdSprite)
{
	BirdSprite.setColor(sf::Color::Red);
	BirdSprite.setScale(1.5, 1.5);
	return INVINCIBLE;
}

int TinyBubble::newSkillBird(sf::Sprite& BirdSprite)
{
	BirdSprite.setColor(sf::Color::Green);
	BirdSprite.setScale(0.5, 0.5);
	return TINY;

}

int InvisibleBubble::newSkillBird(sf::Sprite& BirdSprite)
{
	BirdSprite.setColor(sf::Color(255, 255, 255, 80));
	return INVISIBLE;

}

int Bubble::newSkillBird(sf::Sprite& BirdSprite)
{
	return bubbleStrategy->newSkillBird(BirdSprite);
}