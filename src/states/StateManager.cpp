#include "StateManager.h"

void StateManager::setState(std::unique_ptr<State> newState)
{
    this->currentState = std::move(newState);
}

void StateManager::update()
{
    this->currentState->handleInput();
    this->currentState->update();
}

void StateManager::render()
{
    this->currentState->render();
}