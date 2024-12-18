#include "Pipe.h"
#include "Definition.h"
#include <iostream>


Pipe::Pipe(GameDataRef data) : _data(data) {

}

std::vector<sf::Sprite>& Pipe::getSprite()
{
	return pipeSprites;
}

void Pipe::spawnBottomPipe() {
	sf::Sprite sprite(_data->assets->getTexture("Pipe Up"));
	sprite.setPosition(_data->window.getSize().x, _data->window.getSize().y - sprite.getGlobalBounds().height - _pipeSpawnYOffset);
	pipeSprites.push_back(sprite);
}
void Pipe::spawnTopPipe() {
	sf::Sprite sprite(_data->assets->getTexture("Pipe Down"));
	sprite.setPosition(_data->window.getSize().x, -_pipeSpawnYOffset);
	pipeSprites.push_back(sprite);
}
void Pipe::spawnInvisiblePipe() {
	sf::Sprite sprite(_data->assets->getTexture("Pipe Down"));
	sprite.setPosition(_data->window.getSize().x, -_pipeSpawnYOffset);
	sprite.setColor(sf::Color(0, 0, 0, 0));
	pipeSprites.push_back(sprite);
}

void Pipe::movePipes(float dt) {
	for (int i = 0; i < pipeSprites.size();) {
		if (pipeSprites[i].getPosition().x < 0 - pipeSprites[i].getGlobalBounds().width) {
			pipeSprites.erase(pipeSprites.begin() + i);
		}
		else {
			float movement = PIPE_MOVEMENT_SPEED * dt;
			pipeSprites[i].move(-movement, 0);
			i++;
		}
	}
}

void Pipe::drawPipes() {
	for (int i = 0; i < pipeSprites.size(); i++) {
		_data->window.draw(pipeSprites[i]);
	}
}

void Pipe::RandomisePipeOffSet(){
	_pipeSpawnYOffset = rand() % (250);
}
