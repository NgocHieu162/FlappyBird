#pragma once

#include <map>
#include <SFML/Graphics.hpp>


class AssetManager {
private:
	std::map<std::string, sf::Texture> _textures;
	std::map<std::string, sf::Font> _fonts;
	AssetManager() {}
	~AssetManager() {}
public:
	static AssetManager& getInstance() {
		static AssetManager instance;
		return instance;
	}

	AssetManager(const AssetManager&) = delete;
	AssetManager& operator=(const AssetManager&) = delete;

	void loadTexture(std::string name, std::string fileName);
	sf::Texture& getTexture(std::string name);

	void loadFont(std::string name, std::string fileName);
	sf::Font& getFont(std::string name);
};
