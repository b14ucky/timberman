#pragma once

#include "State.h"
#include "StateManager.h"

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
};