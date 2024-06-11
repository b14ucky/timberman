#include "CreditsState.h"

CreditsState::CreditsState()
{
}

CreditsState::CreditsState(sf::RenderWindow* window, StateManager* stateManager, sf::Font& font) : State(window, stateManager)
{
    this->font = font;

    this->initBackground();
    this->initVariables();
    this->initButtons();
    
}

void CreditsState::initBackground() 
{
    this->backgroundTexture.loadFromFile("./assets/textures/menuBackground.png");
    this->backgroundSprite.setTexture(this->backgroundTexture);
    this->backgroundSprite.setPosition(-50, -150);
}
void CreditsState::initVariables() 
{
    this->mouseHeld = false;
}
void CreditsState::initButtons()
{
    this->creditsButton.push_back(Button("BACK", this->font, 40, sf::Color(244, 176, 123), 3, sf::Color(19, 9, 2), sf::Vector2f(this->window->getSize().x / 2, 500)));
}
void CreditsState::initText() {
    
}
void CreditsState::renderCreditsContent()
{
    this->window->draw(this->creditsText);

    for (auto& button : creditsButton) 
    {
        this->window->draw(button);
    }
}
void CreditsState::updateMousePositions()
{
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(mousePosWindow);
}
void CreditsState::updateCreditsContent()
{  
    for (auto& button : creditsButton) {
        if (button.getGlobalBounds().contains(this->mousePosView)) {
            button.setScale(1.15, 1.15);
        }
        else {
            button.setScale(1, 1);
        }
    }
}
void CreditsState::handleInput()
{
    
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (!this->mouseHeld) {
            this->mouseHeld = true;

            if (this->creditsButton[0].getGlobalBounds().contains(this->mousePosView)) {
                this->stateManager->setState(std::make_unique<MenuState>(this->window, this->stateManager, this->font));
            }
           
        }
    }
    else {
        this->mouseHeld = false;
    }
}

void CreditsState::update()
{
    this->updateMousePositions();
    this->updateCreditsContent();
}

void CreditsState::render()
{
    this->window->draw(this->backgroundSprite);
    this->renderCreditsContent();
}

void CreditsState::handleEvent(sf::Event event)
{
}