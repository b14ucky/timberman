#include "Lumberjack.h"

Lumberjack::Lumberjack()
{
    /*Lumberjack class default consturctor*/
}

Lumberjack::Lumberjack(sf::Texture texture, sf::Vector2f position)
{
    /*Lumberjack class parameterized consturcor*/
    this->setPosition(position);
    this->setTexture(texture);
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