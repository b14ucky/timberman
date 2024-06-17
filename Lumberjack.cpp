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
    this->side = Side::left;
}

Lumberjack::Lumberjack(const Lumberjack& other)
{
    /*
        Lumberjack class copy constructor
    */
    this->texture = new sf::Texture(*other.texture);
    this->setTexture(*this->texture);
    this->side = other.side;
    this->positionLeft = other.positionLeft;
    this->positionRight = other.positionRight;
    this->setPosition(other.getPosition());
    this->setScale(other.getScale());
}

Lumberjack::~Lumberjack() {
    delete this->texture;
}

Lumberjack& Lumberjack::operator=(const Lumberjack& other)
{
    if (this == &other) {
        return *this;
    }

    delete this->texture;
    this->texture = new sf::Texture(*other.texture);
    this->setTexture(*this->texture);
    this->side = other.side;
    this->positionLeft = other.positionLeft;
    this->positionRight = other.positionRight;
    this->setPosition(other.getPosition());
    this->setScale(other.getScale());

    return *this;
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
    this->side = Side::left;
    this->setScale(0.23, 0.23);
    this->setPosition(positionLeft);
}

void Lumberjack::moveRight()
{
    this->side = Side::right;
    this->setScale(-0.23, 0.23);
    this->setPosition(positionRight);
    
}

void Lumberjack::render(sf::RenderWindow* window) {
    window->draw(*this);
}

Side Lumberjack::getSide()
{
    return this->side;
}
