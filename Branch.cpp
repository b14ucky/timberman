#include "Branch.h"
#include <iostream>

Branch::Branch()
{
	/*Branch class default constructor*/
}

Branch::Branch(std::string texturePath, int level, int yAxis)
{
	/*Branch class parameterized constructor*/
	this->texture = new sf::Texture;
	this->texture->loadFromFile(texturePath);
	this->setTexture(*this->texture);
	this->side = randomizeSide();
	
	if (this->side == 0) { // 0 = left
		this->xAxis = 50; // CHECK IF LOOKS GOOD
	}
	else // 1 = right
	{
		this->xAxis = 230; // CHECK IF LOOKS GOOD
	}

	this->setPosition(xAxis, yAxis);
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