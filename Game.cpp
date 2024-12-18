#include "Game.h"
#include "GameState.h"
#include <iostream>


Game::Game(int width, int height, std::string title) 
{
	_data = std::shared_ptr<GameData>(&GameData::getInstance(), [](GameData*) {});
	// [](GameData*) {}: su dung ham huy tuy chinh de tranh viec huy doi tuong GameData (singleton)
	_data->window.create(sf::VideoMode(width, height), title,
		sf::Style::Close | sf::Style::Titlebar);
	this->_data->machine->addState(StateRef(new GameState(this->_data)), true);

	this->Run();
}
void Game::Run() {
	float newTime, frameTime, interpolation;

	float currentTime = this->_clock.getElapsedTime().asSeconds();
	float accumulator = 0.0f;

	while (this->_data->window.isOpen()) {
		this->_data->machine->ProcessStateChanges();

		newTime = this->_clock.getElapsedTime().asSeconds();
		frameTime = newTime - currentTime;

		if (frameTime > 0.25f) {
			frameTime = 0.25f;
		}

		currentTime = newTime;
		accumulator += frameTime;
			
		while (accumulator >= dt) {
			this->_data->machine->GetActiveState()->HandleInput();
			this->_data->machine->GetActiveState()->Update(dt);
			accumulator -= dt;
		}
		interpolation = accumulator / dt;
		this->_data->machine->GetActiveState()->Draw(interpolation);
	}
}