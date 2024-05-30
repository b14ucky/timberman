#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <iostream>

#include "StateManager.h"
// !!! CHANGE TO MENU STATE AFTER IMPLEMENTING IT !!!
#include "GameState.h"

class App
{
    /*
     * The App class is the main class of the application. It is responsible for
     * creating the window, handling events, and updating the game state.
     */
private:
    sf::RenderWindow *window;
    sf::VideoMode videoMode;
    sf::Event event;
    sf::Font font;
    StateManager *stateManager;

    // private methods
    void initWindow();
    void initFont();
    void update();
    void render();

public:
    App();
    ~App();
    void run();
};
