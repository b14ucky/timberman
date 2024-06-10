#pragma once

#include <SFML/Graphics.hpp>

class Button : public sf::Text
{
public:
    Button();
    Button(std::string text, sf::Font& font, unsigned int charSize, sf::Color color, float outlineThickness, sf::Color outlineColor, sf::Vector2f position);
    void render(sf::RenderWindow *window);
};

