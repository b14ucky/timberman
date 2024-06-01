#include "Branch.h"
#include <iostream>

Branch::Branch()
{
	/*Branch class default constructor*/
}

Branch::Branch(std::string texturePath, int level)
{
	/*Branch class parameterized constructor*/
	this->texture = new sf::Texture;
	this->texture->loadFromFile(texturePath);
	this->setTexture(*this->texture);

	// make sure that first branch doesn't collide with lumberjack otherwise player would lose instantly
	this->side = level == 1 ? 0 : randomizeSide(); 
	
	if (this->side == 0) { // 0 = right
		this->xAxis = 215;
	}
	else // 1 = left
	{
		this->xAxis = 345; // CHECK IF LOOKS GOOD
		this->setScale(-1, 1);
	}

	this->setLevel(level);
}

bool Branch::randomizeSide() {
	bool side;
	side = rand() % 2;
	std::cout << side;
	return side;
}

void Branch::render(sf::RenderWindow* window) {
	window->draw(*this);
}

void Branch::setLevel(int level)
{
	this->level = level;
	// equation, that calculates y position (yAxis) of branch
	this->yAxis = 732 - this->level * 160;
	this->setPosition(this->xAxis, this->yAxis);
}

int Branch::getLevel() {
	return this->level;
}
