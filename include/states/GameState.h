#pragma once

#include "State.h"
#include "StateManager.h"
#include "Lumberjack.h"

#include <iostream> /*for testing only*/

class GameState : public State
{
private:
    sf::Font font;

public:
    GameState();
    GameState(sf::RenderWindow *window, StateManager *stateManager, sf::Font &font);
    void handleInput() override;
    void update() override;
    void render() override;
    void handleEvent(sf::Event event) override;
};