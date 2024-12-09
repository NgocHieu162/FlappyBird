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
	_data->assets.loadTexture("Bubble", BUBBLE_FILEPATH);


	pipe = new Pipe(_data);
	land = new Land(_data);
	bird = new Bird(_data);

	bubble = new Bubble(_data, INVICIBLE);

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
	//bubble->drawBubble();
	pipe->movePipes(dt);
	land->moveLand(dt);
	bird->moveBird(dt);
	bubble->moveBubble(dt);

	bubble->setSpawnTime(dt);
	if (bird->getSkill() != 0) {
		if (bird->getSkillDuration() > SKILL_DURATION) {
			bird->getSprite().setColor(sf::Color::White);
			bird->setSkill(0);
			bird->setDuration(-bird->getSkillDuration());
		}
		else {
			bird->setDuration(dt);
		}
	}

	if (bubble->getSpawnTime() > BUBBLE_SPAWN_FREQUENCY) {
		bubble->spawnBubble();
		bubble->setSpawnTime(-bubble->getSpawnTime());
	}

	if (clock.getElapsedTime().asSeconds() > PIPE_SPAWN_FREQUENCY) {
		pipe->RandomisePipeOffSet();

		pipe->spawnInvisiblePipe();
		pipe->spawnTopPipe("White");
		pipe->spawnBottomPipe("White");

		clock.restart();
	}

	std::vector<sf::Sprite> bubbleSprites = bubble->getSprite();
	std::vector<sf::Sprite> landSprites = land->getSprite();
	std::vector<sf::Sprite> pipeSprites = pipe->getSprite();

	for (int i = 0; i < bubbleSprites.size(); i++) {
		if (collision.checkCollision(bird->getSprite(), bubbleSprites[i])) {
			bird->setSkill(INVICIBLE);
			bird->getSprite().setColor(sf::Color::Red);
			bubbleSprites.erase(bubbleSprites.begin() + i);
		}

	}
	bubble->setSprite(bubbleSprites); // update the bubbleSprites vector

	


	if (bird->getSkill() != INVICIBLE)
	{
			for (int i = 0; i < landSprites.size(); i++) {
				if (collision.checkCollision(bird->getSprite(), landSprites[i])) {
					_data->machine.addState(StateRef(new GameOverState(_data)), true);
				}
			}

			if (collision.getIsCollide() == false) {
				for (int i = 0; i < pipeSprites.size(); i++) {
					if (collision.checkCollision(bird->getSprite(), pipeSprites[i])) {
						_data->machine.addState(StateRef(new GameOverState(_data)), true);
					}
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
	bubble->drawBubble();

	_data->window.display();
}


