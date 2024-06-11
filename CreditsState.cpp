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
    this->initText();
    
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
    this->creditsButton.push_back(Button("BACK", this->font, 45, sf::Color(244, 176, 123), 3, sf::Color(19, 9, 2), sf::Vector2f(this->window->getSize().x / 2, 380)));
}
void CreditsState::initText() 
{
    this->authorText.setString("AUTHORS:");
    this->authorsNamesText.setString("- Bartlomiej Janoszka\n- Dominik Meisner\n- Karol Piechaczek");
    this->authorText.setCharacterSize(55);
    this->authorsNamesText.setCharacterSize(40);
    this->authorText.setFont(this->font);
    this->authorsNamesText.setFont(this->font);
    this->authorText.setOutlineColor(sf::Color(19, 9, 2));
    this->authorsNamesText.setOutlineColor(sf::Color(19, 9, 2));
    this->authorText.setFillColor(sf::Color(244, 176, 123));
    this->authorsNamesText.setFillColor(sf::Color(244, 176, 123));
    this->authorText.setOutlineThickness(3);
    this->authorsNamesText.setOutlineThickness(3);
    sf::Vector2f textBounds = this->authorText.getGlobalBounds().getSize();
    this->authorText.setOrigin(textBounds.x / 2, textBounds.y / 2);
    this->authorText.setPosition(sf::Vector2f(this->window->getSize().x / 2, 35));
    sf::Vector2f textBounds2 = this->authorsNamesText.getGlobalBounds().getSize();
    this->authorsNamesText.setOrigin(textBounds2.x / 2, textBounds2.y / 2);
    this->authorsNamesText.setPosition(sf::Vector2f(this->window->getSize().x / 2, 135));
}
void CreditsState::renderCreditsContent()
{
    this->window->draw(this->authorText);
    this->window->draw(this->authorsNamesText);

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