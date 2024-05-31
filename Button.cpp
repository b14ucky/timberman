#include "Button.h"

Button::Button() {}

Button::Button(std::string text, sf::Font& font, unsigned int charSize, sf::Color color, sf::Vector2f position)
{
    this->setString(text);
    this->setFont(font);
    this->setCharacterSize(charSize);
    this->setFillColor(color);
    this->setOrigin(this->getGlobalBounds().getSize().x / 2, this->getGlobalBounds().getSize().y);
    this->setPosition(position);
}