#pragma once

#include <SFML/Graphics.hpp>
#include <ctime>

#include "Side.h"

class Branch : public sf::Sprite
{
private:
	sf::Texture *texture;
	Side side;
	int level; // 1-5
	int xAxis; // left < right
	int yAxis; // 1 < 2 < ... < 5
public:
	Branch();
	Branch(std::string texturePath, int level);
	// rule of three
	Branch(const Branch& other);
	virtual ~Branch();
	Branch& operator=(const Branch& other);
	//
	Side randomizeSide();
	void render(sf::RenderWindow* window);
	int getLevel();
	void setLevel(int level);
	Side getSide();
};
