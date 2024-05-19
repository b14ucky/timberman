#pragma once

#include <memory>

#include "State.h"

class State;

class StateManager
{
private:
    std::unique_ptr<State> currentState;

public:
    void setState(std::unique_ptr<State> newState);
    void update();
    void render();
    void handleEvent(sf::Event event);
};