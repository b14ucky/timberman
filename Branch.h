#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <ctime>

class Branch : public sf::Sprite
{
private:
	sf::Texture *texture;
	bool side; // left - 1, right - 0
	int level; // 1-5
	int xAxis; // left < right
	int yAxis; // 1 < 2 < ... < 5
public:
	Branch();
	Branch(std::string texturePath, int level);
	bool randomizeSide();
	void render(sf::RenderWindow* window);
	int getLevel();
	void setLevel(int level);
};
