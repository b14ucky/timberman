#include "Lumberjack.h"

Lumberjack::Lumberjack()
{
    /*Lumberjack class default constructor*/
}

Lumberjack::Lumberjack(std::string texturePath, sf::Vector2f position)
{
    /*Lumberjack class parameterized constructor*/
    this->texture.loadFromFile(texturePath);
    this->setPosition(position);
    this->setTexture(this->texture);
}

sf::Vector2f Lumberjack::getSize()
{
    /*Returns lumberjack size*/
    return this->getGlobalBounds().getSize();
}

void Lumberjack::moveLeft()
{
    // TODO
}

void Lumberjack::moveRight()
{
    // TODO
}