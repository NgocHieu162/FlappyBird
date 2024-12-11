#pragma once

#include "SFML/Graphics.hpp"
#include "Game.h"


class Bird {
private:
	GameDataRef _data;
	sf::Sprite birdSprite;
	int skill;
	float skill_duration = 0;
public:
	Bird(GameDataRef data);

	int getSkill();
	float getSkillDuration();

	void setDuration(float dt);
	void setSkill(int skillName);

	sf::Sprite& getSprite();
	void moveBird(float dt);
	void drawBird();
};
