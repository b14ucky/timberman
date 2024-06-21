#include "State.h"

State::State() 
{
    this->window = nullptr;
    this->stateManager = nullptr;
}

State::State(sf::RenderWindow *window, StateManager *stateManager)
{
    this->window = window;
    this->stateManager = stateManager;
}