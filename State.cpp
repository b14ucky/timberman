#include "State.h"

State::State() {}

State::State(sf::RenderWindow *window, StateManager *stateManager)
{
    this->window = window;
    this->stateManager = stateManager;
}