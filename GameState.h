#pragma once

#include "State.h"
#include "StateManager.h"
#include "Lumberjack.h"
#include "Branch.h"
#include "Side.h"
#include "Button.h"
#include "MenuState.h"

#include <iostream>
#include <deque>
#include <vector>
#include <sstream>
#include <fstream>
#include <utility>

class GameState : public State
{
private:
    sf::Font font;

    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;

    std::deque<Branch> branches;
    int quantityOfBranches;

    Lumberjack lumberjack;

    int score;
    sf::Text scoreText;

    sf::Clock clock;
    sf::Time elapsedTime;
    sf::Time deltaTime;
    float timerSizeDecay;
    sf::RectangleShape timer;

    int previousUpdateScore;

    bool isGameOver;

    sf::RectangleShape endGameMenuBackground;
    std::vector<Button> endGameMenuButtons;

    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;
    bool mouseHeld;

    sf::String playerName;
    sf::Text inputField;
    sf::Text infoText;

    void initBackground();
    void initVariable();
    void initBranches();
    void updateBranches();
    void initText();
    void initTimer();
    void initEndGameMenu();

    bool checkCollision();
    void updateText();
    void updateTimer();
    void resetTimer();
    void updateTimerSizeDecay();
    void checkTimeOver();
    void renderEndGameMenu();
    void updateMousePositions();
    void updateEndGameMenu();
    void saveScore();

public:
    GameState();
    GameState(sf::RenderWindow *window, StateManager *stateManager, sf::Font &font);
    void handleInput() override;
    void update() override;
    void render() override;
    void handleEvent(sf::Event event) override;
};