#pragma once
#include "State.h"
#include "StateManager.h"
#include "State.h"
#include "Button.h"
#include "MenuState.h"


class HowToPlayyState : public State
{
private:
    sf::Font font;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;
    bool mouseHeld;
    std::vector<Button> creditsButton;
    sf::Text title;
    sf::Text instruction;

    void initBackground();
    void initVariables();
    void initButtons();
    void initText();
    void updateMousePositions();
    void renderCreditsContent();
    void updateCreditsContent();

public:
    HowToPlayyState();
    HowToPlayyState(sf::RenderWindow* window, StateManager* stateManager, sf::Font& font);
    void handleInput() override;
    void update() override;
    void render() override;
    void handleEvent(sf::Event event) override;
};
