#include "GameState.h"
#include <vector>

void GameState::initBackground() {
    this->backgroundTexture.loadFromFile("./assets/textures/background.png");
    this->backgroundSprite.setTexture(backgroundTexture);
    this->backgroundSprite.setScale(1.25, 1.02);
}

void GameState::initBranches() {
    
    for (int i = 0; i < quantityOfBranches; i++)
    {
        int level = i + 1;
        int yAxis = 770 - level * 125; // equation, that calculate location (yAxis) of branch
        Branches.push_back(Branch("./assets/textures/branch.png", level, yAxis));
    }
}

void GameState::initVariable() {
    quantityOfBranches = 6;
}

GameState::GameState() {}

GameState::GameState(sf::RenderWindow *window, StateManager *stateManager, sf::Font &font) : State(window, stateManager)
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
    sf::Vector2f position(0, 600);
    Lumberjack lumberjack("./assets/textures/lumberjack.png", position);
    lumberjack.setScale(0.25, 0.25);
    lumberjack.render(this->window);

    for (int i = 0; i < quantityOfBranches; i++)
    {
        Branches[i].render(this->window);
    }
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