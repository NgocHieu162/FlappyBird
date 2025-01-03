#pragma once

#include "SFML/Graphics.hpp"
#include "Game.h"
#include <vector>
#include "Collision.h"
#include "Bubble.h"
#include "Pipe.h"
#include "Land.h"

class Bird {
private:
	GameDataRef _data;
	sf::Sprite birdSprite;
	int skill;
	float skill_duration = 0;

	bool isFlying = false;
	sf::Vector2<float> position;
	sf::Vector2<float> velocity;
	sf::Vector2<float> acceleration;

public:
	Bird(GameDataRef data);

	int getSkill();
	float getSkillDuration();

	void setDuration(float dt);
	void setSkill(int skillName);

	sf::Sprite& getSprite();
	void animateBird(sf::Clock clock);
	void moveBird(float dt);
	void handler(float dt);
	void update();
	void drawBird();
	bool isAlive(std::vector<sf::Sprite>& Pipes,std::vector<sf::Sprite>& Lands, Bubble& Bubbles, float dt);
};