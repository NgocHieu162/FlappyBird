#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "StateMachine.h"
#include "AssetManager.h"
#include "InputManager.h"


struct GameData {
    StateMachine* machine;
    sf::RenderWindow window;
    AssetManager* assets;
    InputManager* input;

    static GameData& getInstance() {
        static GameData instance;
        return instance;
    }

    GameData(const GameData&) = delete;
    GameData& operator=(const GameData&) = delete;

private:
    GameData(){
        machine = &StateMachine::getInstance();
		assets = &AssetManager::getInstance();
		input = &InputManager::getInstance();
    }
};

typedef std::shared_ptr<GameData> GameDataRef;

class Game {
private:
	const float dt = 1.0f / 60.0f;
	sf::Clock _clock;

    GameDataRef _data;

	void Run();
public:
	Game(int width, int height, std::string title);
};