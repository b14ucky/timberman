#pragma once

#include <SFML/Graphics.hpp>

class Lumberjack : public sf::Sprite
{
public:
    Lumberjack();
    Lumberjack(sf::Texture texture, sf::Vector2f position);
    sf::Vector2f getSize();
    void moveLeft();
    void moveRight();
};