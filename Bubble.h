#pragma once

#include "Definition.h"
#include "Game.h"
#include "SFML/Graphics.hpp"
#include <vector>


class Bubble {
private :
	std::vector<sf::Sprite> bubbleSprites;
	GameDataRef _data;
	int skillName;
	float bb_spawn_time = 0;
	float skillTime = 0;
public:
	
	Bubble(GameDataRef _data,int skillName);

	std::vector<sf::Sprite>& getSprite();
	void setSprite(std::vector<sf::Sprite> bubbleSprites);

	float getSpawnTime();
	void setSpawnTime(float dt);

	void spawnBubble();
	void moveBubble(float dt);
	void drawBubble();


};
