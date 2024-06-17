#pragma once

#include <SFML/Graphics.hpp>

#include "Side.h"

class Lumberjack : public sf::Sprite
{
private:
    sf::Texture *texture;
    Side side;
    sf::Vector2f positionLeft;
    sf::Vector2f positionRight;
    void initPositions();

public:
    Lumberjack();
    Lumberjack(std::string texturePath);
    Lumberjack(const Lumberjack& other);
    virtual ~Lumberjack();
    Lumberjack& operator=(const Lumberjack& other);
    sf::Vector2f getSize();
    void moveLeft();
    void moveRight();
    void render(sf::RenderWindow* window);
    Side getSide();
};