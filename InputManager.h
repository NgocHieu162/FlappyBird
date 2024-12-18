#pragma once
#include <SFML/Graphics.hpp>

class InputManager {
private:
	InputManager() {}
	~InputManager() {}
public:
	
	static InputManager& getInstance() {
		static InputManager instance;
		return instance;
	}

	InputManager(const InputManager&) = delete;
	InputManager& operator=(const InputManager&) = delete;

	bool isSpriteClicked(sf::Sprite object, sf::Mouse::Button button,
		sf::RenderWindow& window);
	sf::Vector2i GetMousePosition(sf::RenderWindow &window);
};
