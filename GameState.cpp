#include "GameState.h"
#include <vector>

void GameState::initBackground() {
    this->backgroundTexture.loadFromFile("./assets/textures/background.png");
    this->backgroundSprite.setTexture(backgroundTexture);
    this->backgroundSprite.setScale(1, 0.83);
}

void GameState::initBranches() {
    
    for (int i = 0; i < quantityOfBranches; i++)
    {
        int level = i + 1;
        int yAxis = 732 - level * 160; // equation, that calculates y position (yAxis) of branch
        Branches.push_back(Branch("./assets/textures/branch.png", level, yAxis));
    }
}

void GameState::initVariable() {
    quantityOfBranches = 6;
}

GameState::GameState() {}

GameState::GameState(sf::RenderWindow* window, StateManager* stateManager, sf::Font& font) : State(window, stateManager)
{
    this->font = font;
    this->initBackground();
    this->initVariable();
    this->initBranches();
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
    this->window->draw(this->backgroundSprite);
    sf::Vector2f position(50, 550);
    Lumberjack lumberjack("./assets/textures/lumberjack.png", position);
    lumberjack.render(this->window);

    for (int i = 0; i < quantityOfBranches; i++)
    {
        Branches[i].render(this->window);
    }

    // this draws a red line in the middle to help with positioning
    sf::RectangleShape rect(sf::Vector2f(1, 800));
    rect.setFillColor(sf::Color::Red);
    rect.setPosition(this->window->getSize().x / 2 - rect.getSize().x / 2, 0);
    this->window->draw(rect);
    ///
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