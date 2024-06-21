#include "CreditsState.h"

CreditsState::CreditsState()
{
    this->mouseHeld = false;
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
    this->creditsButton.push_back(Button("BACK", this->font, 45, sf::Color(244, 176, 123), 3, sf::Color(19, 9, 2), sf::Vector2f(this->window->getSize().x / 2.f, 380)));
}
void CreditsState::initText()
{
    this->title.setString("AUTHORS:");
    this->instruction.setString("- Bartlomiej Janoszka\n- Dominik Meisner\n- Karol Piechaczek");
    this->title.setCharacterSize(55);
    this->instruction.setCharacterSize(40);
    this->title.setFont(this->font);
    this->instruction.setFont(this->font);
    this->title.setOutlineColor(sf::Color(19, 9, 2));
    this->instruction.setOutlineColor(sf::Color(19, 9, 2));
    this->title.setFillColor(sf::Color(244, 176, 123));
    this->instruction.setFillColor(sf::Color(244, 176, 123));
    this->title.setOutlineThickness(3);
    this->instruction.setOutlineThickness(3);
    sf::Vector2f textBounds = this->title.getGlobalBounds().getSize();
    this->title.setOrigin(textBounds.x / 2, textBounds.y / 2);
    this->title.setPosition(sf::Vector2f(this->window->getSize().x / 2.f, 35));
    sf::Vector2f textBounds2 = this->instruction.getGlobalBounds().getSize();
    this->instruction.setOrigin(textBounds2.x / 2, textBounds2.y / 2);
    this->instruction.setPosition(sf::Vector2f(this->window->getSize().x / 2.f, 135));
}
void CreditsState::renderCreditsContent()
{
    this->window->draw(this->title);
    this->window->draw(this->instruction);

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
            button.setScale(1.15f, 1.15f);
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