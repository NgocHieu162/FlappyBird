#pragma once

#include "SFML/Graphics.hpp"
#include "Game.h"
#include <vector>
#include <string>

class Pipe {
private:
	GameDataRef _data;
	std::vector<sf::Sprite> pipeSprites;

	int _pipeSpawnYOffset;
public:
	Pipe(GameDataRef data);
	
	std::vector<sf::Sprite>& getSprite();
	void spawnBottomPipe(std::string color);
	void spawnTopPipe(std::string color);
	void spawnInvisiblePipe();
	void movePipes(float dt);
	void drawPipes();
	void RandomisePipeOffSet();
};
