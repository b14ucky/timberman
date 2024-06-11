#include "MenuState.h"

void MenuState::updateMousePositions()
{
    /*
        Update the mouse positions
    */
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(mousePosWindow);
}

void MenuState::renderMainMenuContent() {
    /*
        Renders the main menu contents (buttons and text)
    */
    this->window->draw(this->gameNameText);

    for (auto &button : mainMenuButtons) {
        this->window->draw(button);
    }
}

void MenuState::updateMainMenuContent() {
    /*
        Updates the main menu content (buttons and text)
    */
    for (auto& button : mainMenuButtons) {
        if (button.getGlobalBounds().contains(this->mousePosView)) {
            button.setScale(1.15, 1.15);
        }
        else {
            button.setScale(1, 1);
        }
    }
}

void MenuState::initBackground() {
    /*
        Loads the background texture and sets its position
    */
    this->backgroundTexture.loadFromFile("./assets/textures/menuBackground.png");
    this->backgroundSprite.setTexture(this->backgroundTexture);
    this->backgroundSprite.setPosition(-50, -150);
}

void MenuState::initVariables() {
    /*
        Initializes MenuState variables
    */
    this->mouseHeld = false;
}

void MenuState::initButtons()
{
    /*
        Initializes MenuState buttons
    */
    this->mainMenuButtons.push_back(Button("PLAY", this->font, 40, sf::Color(244, 176, 123), 3, sf::Color(19, 9, 2), sf::Vector2f(this->window->getSize().x / 2, 350)));
    this->mainMenuButtons.push_back(Button("LEADERBOARD", this->font, 40, sf::Color(244, 176, 123), 3, sf::Color(19, 9, 2), sf::Vector2f(this->window->getSize().x / 2, 410)));
    this->mainMenuButtons.push_back(Button("HOW TO PLAY", this->font, 40, sf::Color(244, 176, 123), 3, sf::Color(19, 9, 2), sf::Vector2f(this->window->getSize().x / 2, 470)));
    this->mainMenuButtons.push_back(Button("CREDITS", this->font, 40, sf::Color(244, 176, 123), 3, sf::Color(19, 9, 2), sf::Vector2f(this->window->getSize().x / 2, 530)));
    this->mainMenuButtons.push_back(Button("EXIT", this->font, 40, sf::Color(244, 176, 123), 3, sf::Color(19, 9, 2), sf::Vector2f(this->window->getSize().x / 2, 590)));
}

void MenuState::initText() {
    /* 
        Initializes MenuState text
    */
    this->gameNameText.setString("Timberman");
    this->gameNameText.setCharacterSize(80);
    this->gameNameText.setFont(this->font);
    this->gameNameText.setFillColor(sf::Color(238, 132, 52));
    this->gameNameText.setOutlineThickness(3);
    this->gameNameText.setOutlineColor(sf::Color(19, 9, 2));

    // set text's origin to be its center so it's easier to position
    sf::Vector2f textBounds = this->gameNameText.getGlobalBounds().getSize();
    this->gameNameText.setOrigin(textBounds.x / 2, textBounds.y / 2);
    this->gameNameText.setPosition(sf::Vector2f(this->window->getSize().x / 2, 100));
}

MenuState::MenuState()
{
}

MenuState::MenuState(sf::RenderWindow* window, StateManager* stateManager, sf::Font& font) : State(window, stateManager)
{
	this->font = font;

    this->initBackground();
    this->initVariables();
    this->initButtons();
    this->initText();
}

void MenuState::handleInput()
{
    /*
        Handles the mouse input (checks if button was clicked performs specified action)
    */
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (!this->mouseHeld) {
            this->mouseHeld = true;

            if (this->mainMenuButtons[0].getGlobalBounds().contains(this->mousePosView)) {
                this->stateManager->setState(std::make_unique<GameState>(this->window, this->stateManager, this->font));
            }
            else if (this->mainMenuButtons[2].getGlobalBounds().contains(this->mousePosView)) {
                this->stateManager->setState(std::make_unique<HowToPlayyState>(this->window, this->stateManager, this->font));
            }
            else if (this->mainMenuButtons[3].getGlobalBounds().contains(this->mousePosView)) {
                this->stateManager->setState(std::make_unique<CreditsState>(this->window, this->stateManager, this->font));
            }
            else if (this->mainMenuButtons[4].getGlobalBounds().contains(this->mousePosView)) {
                this->window->close();
            }
        }
    }
    else {
        this->mouseHeld = false;
    }
}

void MenuState::update()
{
    /*
        Updates objects before rendering them
    */
    this->updateMousePositions();
    this->updateMainMenuContent();
}

void MenuState::render()
{
    /*
        Renders all objects
    */
    this->window->draw(this->backgroundSprite);
    this->renderMainMenuContent();
}

void MenuState::handleEvent(sf::Event event)
{
}

