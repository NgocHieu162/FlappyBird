#pragma once

#include "Definition.h"
#include "Game.h"
#include "SFML/Graphics.hpp"
#include <vector>


//class Bubble {
//private :
//	std::vector<sf::Sprite> bubbleSprites;
//	GameDataRef _data;
//	int skillName;
//	float bb_spawn_time = 0;
//	float skillTime = 0;
//public:
//	
//	Bubble(GameDataRef _data,int skillName);
//
//	std::vector<sf::Sprite>& getSprite();
//	void setSprite(std::vector<sf::Sprite> bubbleSprites);
//
//	float getSpawnTime();
//	void setSpawnTime(float dt);
//
//	void spawnBubble();
//	void moveBubble(float dt);
//	void drawBubble();
//
//
//};

// Strategy Pattern

// interface
class BubbleStrategy {
public:
	virtual void spawnBubble(GameDataRef _data, std::vector<sf::Sprite>& bubbleSprites) = 0;
	virtual int newSkillBird(sf::Sprite &BirdSprite)= 0;
};

// concrete class

class InvincibleBubble : public BubbleStrategy {
public:
	void spawnBubble(GameDataRef _data, std::vector<sf::Sprite> &bubbleSprites);
	int newSkillBird(sf::Sprite &BirdSprite);
};

class TinyBubble : public BubbleStrategy {
public: 	
	void spawnBubble(GameDataRef _data, std::vector<sf::Sprite>& bubbleSprites);
	int newSkillBird(sf::Sprite &BirdSprite);
};
class InvisibleBubble : public BubbleStrategy {
public: 	
	void spawnBubble(GameDataRef _data, std::vector<sf::Sprite>& bubbleSprites);
	int newSkillBird(sf::Sprite& BirdSprite);
};

class Bubble {
private:
	std::vector<sf::Sprite> bubbleSprites;
	GameDataRef _data;
	float bb_spawn_time = 0;
	BubbleStrategy* bubbleStrategy;
public:
	Bubble(GameDataRef _data);
	std::vector<sf::Sprite>& getSprite();
	void setSprite(std::vector<sf::Sprite> bubbleSprites);
	float getSpawnTime();
	void setSpawnTime(float dt);
	void moveBubble(float dt);
	void drawBubble();
	void SpawnRandomBubble();
	void setBubbleStrategy(BubbleStrategy* bubbleStrategy);
	int newSkillBird(sf::Sprite& BirdSprite);

};

