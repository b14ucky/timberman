#include "GameState.h"

GameState::GameState() {}

GameState::GameState(sf::RenderWindow *window, StateManager *stateManager, sf::Font &font) : State(window, stateManager)
{
    this->font = font;
}

void GameState::handleInput()
{
    /*IMPLEMENT THIS*/
}

void GameState::update()
{
    /*IMPLEMENT THIS*/
}

void GameState::render()
{
    sf::Texture texture;
    texture.loadFromFile("./assets/textures/test_texture.png", sf::IntRect(100, 100, 100, 100));
    sf::Vector2f position(0, 0);
    Lumberjack lumberjack(texture, position);
    lumberjack.setColor(sf::Color::Black);
    this->window->draw(lumberjack);
}

void GameState::handleEvent(sf::Event event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.scancode == sf::Keyboard::Scan::Left)
        {
            std::cout << "lewy" << std::endl; /*implement player movement here*/
        }
        if (event.key.scancode == sf::Keyboard::Scan::Right)
        {
            std::cout << "prawy" << std::endl; /*implement player movement here*/
        }
    }
}