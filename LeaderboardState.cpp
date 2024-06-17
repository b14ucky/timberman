#include "LeaderboardState.h"
#include <fstream>

LeaderboardState::LeaderboardState()
{
}

LeaderboardState::LeaderboardState(sf::RenderWindow* window, StateManager* stateManager, sf::Font& font) : State(window, stateManager)
{
    this->font = font;

    this->initBackground();
    this->initVariables();
    this->initButtons();
    this->initText();

}

void LeaderboardState::initBackground()
{
    this->backgroundTexture.loadFromFile("./assets/textures/menuBackground.png");
    this->backgroundSprite.setTexture(this->backgroundTexture);
    this->backgroundSprite.setPosition(-50, -150);
}
void LeaderboardState::initVariables()
{
    this->mouseHeld = false;
}
void LeaderboardState::initButtons()
{
    this->lbButton.push_back(Button("BACK", this->font, 45, sf::Color(244, 176, 123), 3, sf::Color(19, 9, 2), sf::Vector2f(this->window->getSize().x / 2.f, 560)));
}
void LeaderboardState::initText()
{
    
    this->title.setString("LEADERBOARD:");
    std::string score{"\n"};
    std::string nick{};
    std::string points{};
    std::string line{};
    bool check=false;
    char x{};
    int position = 0;
    std::fstream file;
    file.open("assets/leader.txt", std::ios::in);
    if (file.good() == false)
    {
        this->instruction.setString("Leaderboard is empty!");
    }
    else
    {
        if (!getline(file, line)) {
            this->instruction.setString("Leaderboard is empty!");
        }
        file.clear();
        file.seekg(0, std::ios::beg);

        while (getline(file, line))
        {
            check = false;
            nick="";
            points = "";
            
            for (int i = 0; i < line.length(); i++)
            {
                x = line[i];
                if (x==':')
                {
                    check = true;
                    continue;
                }
                if (check==false)
                {
                    nick = nick + x;
                }
                else
                {
                    points = points + x;
                }
            }
            position++;
            score = score + "\n" + std::to_string(position) + ". " + nick + ": " + points;
            this->instruction.setString(score);
        }
        file.close();
    }
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
    this->instruction.setPosition(sf::Vector2f(this->window->getSize().x / 2.f, 240));
}
void LeaderboardState::renderLBContent()
{
    this->window->draw(this->title);
    this->window->draw(this->instruction);

    for (auto& button : lbButton)
    {
        this->window->draw(button);
    }
}
void LeaderboardState::updateMousePositions()
{
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(mousePosWindow);
}
void LeaderboardState::updateLBContent()
{
    for (auto& button : lbButton) {
        if (button.getGlobalBounds().contains(this->mousePosView)) {
            button.setScale(1.15f, 1.15f);
        }
        else {
            button.setScale(1, 1);
        }
    }
}
void LeaderboardState::handleInput()
{

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (!this->mouseHeld) {
            this->mouseHeld = true;

            if (this->lbButton[0].getGlobalBounds().contains(this->mousePosView)) {
                this->stateManager->setState(std::make_unique<MenuState>(this->window, this->stateManager, this->font));
            }

        }
    }
    else {
        this->mouseHeld = false;
    }
}

void LeaderboardState::update()
{
    this->updateMousePositions();
    this->updateLBContent();
}

void LeaderboardState::render()
{
    this->window->draw(this->backgroundSprite);
    this->renderLBContent();
}

void LeaderboardState::handleEvent(sf::Event event)
{
}