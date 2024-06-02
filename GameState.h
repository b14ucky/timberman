#pragma once

#include "State.h"
#include "StateManager.h"
#include "Lumberjack.h"
#include "Branch.h"

#include <iostream> /*for testing only*/
#include <deque>

class GameState : public State
{
private:
    sf::Font font;

    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;

    std::deque<Branch> branches;
    int quantityOfBranches;

    Lumberjack lumberjack;

    void initBackground();
    void initVariable();
    void initBranches();
    void updateBranches();

public:
    GameState();
    GameState(sf::RenderWindow *window, StateManager *stateManager, sf::Font &font);
    void handleInput() override;
    void update() override;
    void render() override;
    void handleEvent(sf::Event event) override;
};