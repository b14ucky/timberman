#include "Lumberjack.h"

Lumberjack::Lumberjack()
{
    /*Lumberjack class default constructor*/
}

Lumberjack::Lumberjack(std::string texturePath)
{
    /*Lumberjack class parameterized constructor*/
    this->texture = new sf::Texture;
    this->texture->loadFromFile(texturePath);
    this->setTexture(*this->texture);
    this->setScale(0.23, 0.23);
    this->initPositions();
}

sf::Vector2f Lumberjack::getSize()
{
    /*Returns lumberjack size*/
    return this->getGlobalBounds().getSize();
}

void Lumberjack::initPositions()
{
    this->positionLeft = sf::Vector2f(50, 550);
    this->positionRight = sf::Vector2f(510, 550);
    this->setPosition(positionLeft);
}

void Lumberjack::moveLeft()
{
    this->setScale(0.23, 0.23);
    this->setPosition(positionLeft);
}

void Lumberjack::moveRight()
{
   
    this->setScale(-0.23, 0.23);
    this->setPosition(positionRight);
    
}

void Lumberjack::render(sf::RenderWindow* window) {
    window->draw(*this);
}