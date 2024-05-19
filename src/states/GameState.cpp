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
    sf::RectangleShape shape(sf::Vector2f(100, 100));
    shape.setFillColor(sf::Color::Black);
    shape.setPosition(this->window->getSize().x / 2 - shape.getSize().x / 2, this->window->getSize().y / 2 - shape.getSize().y / 2);
    this->window->draw(shape);
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