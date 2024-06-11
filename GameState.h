#pragma once

#include "State.h"
#include "StateManager.h"
#include "Lumberjack.h"
#include "Branch.h"
#include "Side.h"

#include <iostream> /*for testing only*/
#include <deque>
#include <sstream>

class GameState : public State
{
private:
    sf::Font font;

    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;

    std::deque<Branch> branches;
    int quantityOfBranches;

    Lumberjack lumberjack;

    int score;
    sf::Text scoreText;

    void initBackground();
    void initVariable();
    void initBranches();
    void updateBranches();
    void initText();

    bool checkCollision();
    void updateText();

public:
    GameState();
    GameState(sf::RenderWindow *window, StateManager *stateManager, sf::Font &font);
    void handleInput() override;
    void update() override;
    void render() override;
    void handleEvent(sf::Event event) override;
};