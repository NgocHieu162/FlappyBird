#include "GameState.h"
#include "GameOverState.h"
#include "Definition.h"
#include <iostream>

GameState::GameState(GameDataRef data) : _data(data)
{
}

void GameState::Init()
{
	_data->assets.loadTexture("Game Background", GAME_BACKGROUND_FILEPATH);
	_data->assets.loadTexture("Pipe Up", PIPE_UP_FILEPATH);
	_data->assets.loadTexture("Pipe Down", PIPE_DOWN_FILEPATH);
	_data->assets.loadTexture("Land", LAND_FILEPATH);
	_data->assets.loadTexture("Bird", BIRD_FILEPATH);

	pipe = new Pipe(_data);
	land = new Land(_data);
	bird = new Bird(_data);

	_background.setTexture(this->_data->assets.getTexture("Game Background"));
}

void GameState::HandleInput()
{
	sf::Event event;
	while(_data->window.pollEvent(event)) {
		if (sf::Event::Closed == event.type) {
			_data->window.close();
		}
	}
}

void GameState::Update(float dt)
{
	pipe->movePipes(dt);
	land->moveLand(dt);
	bird->moveBird(dt);
	
	if (clock.getElapsedTime().asSeconds() > PIPE_SPAWN_FREQUENCY) {
		pipe->RandomisePipeOffSet();

		pipe->spawnInvisiblePipe();
		pipe->spawnTopPipe("White");
		pipe->spawnBottomPipe("White");

		clock.restart();
	}
	std::vector<sf::Sprite> landSprites = land->getSprite();
	std::vector<sf::Sprite> pipeSprites = pipe->getSprite();
	for(int i = 0; i< landSprites.size(); i++){
		if (collision.checkCollision(bird->getSprite(), landSprites[i])) {
			_data->machine.addState(StateRef(new GameOverState(_data)), true);
		}
	}
	if(collision.getIsCollide() == false){
		for (int i = 0; i < pipeSprites.size(); i++) {
			if (collision.checkCollision(bird->getSprite(), pipeSprites[i])) {
				_data->machine.addState(StateRef(new GameOverState(_data)), true);
			}
		}
	}
}

void GameState::Draw(float dt)
{
	_data->window.clear();

	_data->window.draw(_background);
	pipe->drawPipes();
	land->drawLand();
	bird->drawBird();

	_data->window.display();
}


