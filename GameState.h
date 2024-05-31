#pragma once

#include "State.h"
#include "StateManager.h"
#include "Lumberjack.h"
#include "Branch.h"

#include <iostream> /*for testing only*/
#include <vector>

class GameState : public State
{
private:
    sf::Font font;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    void initBackground();
    void initBranches();
    std::vector<Branch> Branches;
    int quantityOfBranches;
    void initVariable();

public:
    GameState();
    GameState(sf::RenderWindow *window, StateManager *stateManager, sf::Font &font);
    void handleInput() override;
    void update() override;
    void render() override;
    void handleEvent(sf::Event event) override;
};