#pragma once

#include <SFML/Graphics.hpp>

class Button : public sf::Text
{
public:
    Button();
    Button(std::string text, sf::Font& font, unsigned int charSize, sf::Color color, sf::Vector2f position);
};

