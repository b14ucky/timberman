#pragma once

#include "State.h"
#include "Button.h"
#include "GameState.h"

#include <iostream>
#include <vector>

class MenuState : public State {
private:
	sf::Font font;

	// mouse variables
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;
	bool mouseHeld;

	// buttons
	std::vector<Button> mainMenuButtons;

	// text
	sf::Text gameNameText;

	// private methods
	void updateMousePositions();
	void renderMainMenuContent();
	void updateMainMenuContent();

	// init methods
	void initVariables();
	void initButtons();
	void initText();

public:
	MenuState();
	MenuState(sf::RenderWindow* window, StateManager* stateManager, sf::Font& font);
	void handleInput() override;
	void update() override;
	void render() override;
	void handleEvent(sf::Event event) override;
};