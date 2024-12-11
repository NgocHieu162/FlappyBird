#include "Bubble.h"
#include "Definition.h"

Bubble::Bubble(GameDataRef _data, int skillName) : _data(_data)
{
	this->skillName = skillName;
}

void Bubble::drawBubble()
{
	for (int i = 0; i < bubbleSprites.size(); i++) {
		_data->window.draw(bubbleSprites[i]);
	}
}

void Bubble::spawnBubble()
{
	sf::Sprite sprite(_data->assets.getTexture("Bubble"));
	sprite.setPosition(_data->window.getSize().x, _data->window.getSize().y/2);
	if (skillName == INVICIBLE) {
		sprite.setColor(sf::Color::Red);
	}
	//else if (skillName == SLOW) {
	//	sprite.setColor(sf::Color::Green);
	//}
	//else if (skillName == FAST) {
	//	sprite.setColor(sf::Color::Blue);
	//}
	//else if (skillName == BUBBLE) {
	//	sprite.setColor(sf::Color::Yellow);
	//}
	//else {
	//	sprite.setColor(sf::Color::White);
	//}
	bubbleSprites.push_back(sprite);
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