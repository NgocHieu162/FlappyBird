#include "GameOverState.h"
#include "GameState.h"
#include "Definition.h"

GameOverState::GameOverState(GameDataRef data) : _data(data)
{
}

void GameOverState::Init()
{
	_data->assets.loadTexture("Game Background", GAME_BACKGROUND_FILEPATH);
	_data->assets.loadTexture("Game Over Title", GAME_OVER_TITLE_FILEPATH);

	_background.setTexture(this->_data->assets.getTexture("Game Background"));
	_gameOverTitle.setTexture(this->_data->assets.getTexture("Game Over Title"));
	_gameOverTitle.setPosition(160, 400);
}

void GameOverState::HandleInput()
{
	sf::Event event;
	while(_data->window.pollEvent(event)) {
		if (sf::Event::Closed == event.type) {
			_data->window.close();
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
			_data->machine.addState(StateRef(new GameState(_data)), true);
		}
	}
}

void GameOverState::Update(float dt)
{
}

void GameOverState::Draw(float dt)
{
	_data->window.clear();

	_data->window.draw(_background);
	_data->window.draw(_gameOverTitle);

	_data->window.display();
}
