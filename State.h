#pragma once

#include <SFML/Graphics.hpp>

#include "StateManager.h"

class StateManager;

class State
{
public:
    sf::RenderWindow *window;
    StateManager *stateManager;
    State();
    State(sf::RenderWindow *window, StateManager *stateManager);
    virtual ~State() = default;
    virtual void handleInput() = 0;
    virtual void update() = 0;
    virtual void render() = 0;
    virtual void handleEvent(sf::Event event) = 0;
};