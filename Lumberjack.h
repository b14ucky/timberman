#pragma once

#include <SFML/Graphics.hpp>

class Lumberjack : public sf::Sprite
{
private:
    sf::Texture texture;

public:
    Lumberjack();
    Lumberjack(std::string texturePath, sf::Vector2f position);
    sf::Vector2f getSize();
    void moveLeft();
    void moveRight();
    void render(sf::RenderWindow* window);
};