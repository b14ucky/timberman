#include "HowToPlayyState.h"

HowToPlayyState::HowToPlayyState()
{
}

HowToPlayyState::HowToPlayyState(sf::RenderWindow* window, StateManager* stateManager, sf::Font& font) : State(window, stateManager)
{
	this->font = font;

	this->initBackground();
	this->initVariables();
	this->initButtons();
	this->initText();

}

void HowToPlayyState::initBackground()
{
	this->backgroundTexture.loadFromFile("./assets/textures/menuBackground.png");
	this->backgroundSprite.setTexture(this->backgroundTexture);
	this->backgroundSprite.setPosition(-50, -150);
}
void HowToPlayyState::initVariables()
{
	this->mouseHeld = false;
}
void HowToPlayyState::initButtons()
{
	this->creditsButton.push_back(Button("BACK", this->font, 45, sf::Color(244, 176, 123), 3, sf::Color(19, 9, 2), sf::Vector2f(this->window->getSize().x / 2.f, 555)));
}
void HowToPlayyState::initText()
{
	std::string instructionText =
		"Use the left and right arrow keys on your keyboard \n"
		"to chop the tree. Your goal is to chop down as much \n"
		"of the tree as possible and score as many points as \n"
		"you can. As you chop, branches will appear on both \n"
		"sides of the tree, and you must avoid them to continue \n"
		"playing. Switch sides quickly to avoid getting hit by \n"
		"a branch. The game speeds up as you progress, making \n"
		"it more challenging. There is a timer that counts down, \n"
		"but each successful chop adds a little more time. If the \n"
		"timer runs out, the game ends. You earn one point for \n"
		"each successful chop. The game ends if you get hit by a \n"
		"branch or if the timer runs out. Try to achieve \n"
		"the highest score by chopping quickly and avoiding \n"
		"branches!";
	this->title.setString("HOW TO PLAY:");
	this->instruction.setString(instructionText);
	this->title.setCharacterSize(55);
	this->instruction.setCharacterSize(19);
	this->title.setFont(this->font);
	this->instruction.setFont(this->font);
	this->title.setOutlineColor(sf::Color(19, 9, 2));
	this->instruction.setOutlineColor(sf::Color(19, 9, 2));
	this->title.setFillColor(sf::Color(244, 176, 123));
	this->instruction.setFillColor(sf::Color(244, 176, 123));
	this->title.setOutlineThickness(3);
	this->instruction.setOutlineThickness(1);
	sf::Vector2f textBounds = this->title.getGlobalBounds().getSize();
	this->title.setOrigin(textBounds.x / 2, textBounds.y / 2);
	this->title.setPosition(sf::Vector2f(this->window->getSize().x / 2.f, 35));
	sf::Vector2f textBounds2 = this->instruction.getGlobalBounds().getSize();
	this->instruction.setOrigin(textBounds2.x / 2, textBounds2.y / 2);
	this->instruction.setPosition(sf::Vector2f(this->window->getSize().x / 2.f, 250));
}
void HowToPlayyState::renderCreditsContent()
{
	this->window->draw(this->title);
	this->window->draw(this->instruction);

	for (auto& button : creditsButton)
	{
		this->window->draw(button);
	}
}
void HowToPlayyState::updateMousePositions()
{
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(mousePosWindow);
}
void HowToPlayyState::updateCreditsContent()
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
void HowToPlayyState::handleInput()
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

void HowToPlayyState::update()
{
	this->updateMousePositions();
	this->updateCreditsContent();
}

void HowToPlayyState::render()
{
	this->window->draw(this->backgroundSprite);
	this->renderCreditsContent();
}

void HowToPlayyState::handleEvent(sf::Event event)
{
}