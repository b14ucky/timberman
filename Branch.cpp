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
	this->side = level == 1 ? Side::right : randomizeSide();
	
	if (this->side == Side::right) {
		this->xAxis = 215;
	}
	else if(this->side == Side::left)
	{
		this->xAxis = 345; // CHECK IF LOOKS GOOD
		this->setScale(-1, 1);
	}

	this->setLevel(level);
}

Branch::Branch(const Branch& other) {
	/*
		Branch class copy constructor
	*/
	this->texture = new sf::Texture(*other.texture);
	this->setTexture(*this->texture);
	this->level = other.level;
	this->side = other.side;
	this->xAxis = other.xAxis;
	this->yAxis = other.yAxis;
	this->setPosition(other.getPosition());
	this->setScale(other.getScale());
}

Branch& Branch::operator=(const Branch& other) {
	if (this == &other) {
		return *this;
	}

	delete this->texture;
	this->texture = new sf::Texture(*other.texture);
	this->setTexture(*this->texture);
	this->level = other.level;
	this->side = other.side;
	this->xAxis = other.xAxis;
	this->yAxis = other.yAxis;
	this->setPosition(other.getPosition());
	this->setScale(other.getScale());

	return *this;
}

Branch::~Branch()
{
	delete this->texture;
}

Side Branch::randomizeSide() {
	return rand() % 2 == 0 ? Side::left : Side::right;
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
