#include "GameState.h"

void GameState::initBackground() {
    this->backgroundTexture.loadFromFile("./assets/textures/background.png");
    this->backgroundSprite.setTexture(backgroundTexture);
    this->backgroundSprite.setScale(1.f, 0.83f);
}

void GameState::initBranches() {
    
    for (int i = 0; i < quantityOfBranches; i++)
    {
        int level = i + 1;
        this->branches.push_back(Branch("./assets/textures/branch.png", level));
    }
}

void GameState::updateBranches()
{
    this->branches.pop_front();
    for (auto& branch : branches) {
        int currentLevel = branch.getLevel();
        branch.setLevel(currentLevel - 1);

    }
    int level = this->quantityOfBranches;
    this->branches.push_back(Branch("./assets/textures/branch.png", level));
}

void GameState::initVariable() {
    this->quantityOfBranches = 6;
    this->score = 0;
    this->timerSizeDecay = 1;
    this->deltaTime = sf::seconds(0.1f);
    this->previousUpdateScore = 0;
    this->isGameOver = false;
    this->lumberjack=Lumberjack("./assets/textures/lumberjack.png");
}

void GameState::initText() {
    this->scoreText.setString("0");
    this->scoreText.setFont(this->font);
    this->scoreText.setCharacterSize(55);
    this->scoreText.setOutlineColor(sf::Color::Black);
    this->scoreText.setOutlineThickness(2);
    float screenMiddle = this->window->getSize().x / 2.f;
    this->scoreText.setPosition(screenMiddle - this->scoreText.getGlobalBounds().width / 2, 10);
}

void GameState::initTimer()
{
    sf::Vector2f timerSize(120, 20);
    this->timer.setSize(timerSize);
    float screenMiddle = this->window->getSize().x / 2.f;
    this->timer.setPosition(screenMiddle - this->timer.getSize().x / 2, 0);
    this->timer.setFillColor(sf::Color::Red);
}

void GameState::initEndGameMenu()
{
    sf::Vector2f endGameMenuSize(250, 250);
    this->endGameMenuBackground.setSize(endGameMenuSize);
    this->endGameMenuBackground.setFillColor(sf::Color(255, 255, 255, 224));
    float screenHeightMiddle = this->window->getSize().y / 2.f - this->endGameMenuBackground.getSize().x / 2.f;
    float screenWidthMiddle = this->window->getSize().x / 2.f - this->endGameMenuBackground.getSize().y / 2.f;
    this->endGameMenuBackground.setPosition(screenWidthMiddle, screenHeightMiddle);

    float screenMiddle = this->window->getSize().x / 2.f;
    this->endGameMenuButtons.push_back(Button("Play again", this->font, 40, sf::Color::Black, 0, sf::Color::Black, sf::Vector2f(screenMiddle, 350)));
    this->endGameMenuButtons.push_back(Button("Main menu", this->font, 40, sf::Color::Black, 0, sf::Color::Black, sf::Vector2f(screenMiddle, 450)));
}

bool GameState::checkCollision() {
    /*
        Check if player collided with the next branch
        Retrun: true if collided and false otherwise
    */
    Side lumberjackSide = this->lumberjack.getSide();
    Side nextBranchSide = this->branches[1].getSide();

    if (lumberjackSide == nextBranchSide) {
        std::cout << "collision" << std::endl;
        return true;
    }
    return false;
}

void GameState::updateText()
{
    std::stringstream scoreString;
    scoreString << this->score;
    this->scoreText.setString(scoreString.str());

    float screenMiddle = this->window->getSize().x / 2.f;
    this->scoreText.setPosition(screenMiddle - this->scoreText.getGlobalBounds().width / 2, 10);
}

void GameState::updateTimer()
{
    this->elapsedTime += this->clock.restart();
    if (this->elapsedTime >= this->deltaTime) {
        sf::Vector2f newTimerSize = this->timer.getSize();
        // update timer width
        newTimerSize.x -= this->timerSizeDecay;
        this->timer.setSize(newTimerSize);

        this->elapsedTime = sf::seconds(0);
    }
}

void GameState::resetTimer()
{
    sf::Vector2f newTimerSize = this->timer.getSize();
    newTimerSize.x = 120;
    this->timer.setSize(newTimerSize);
}

void GameState::updateTimerSizeDecay()
{
    if (this->score % 100 == 0 && this->score != 0 && this->previousUpdateScore != this->score) {
        this->previousUpdateScore = this->score;
        this->timerSizeDecay += 0.75;
    }
}

void GameState::checkTimeOver()
{
    float timeLeft = this->timer.getSize().x;
    if (timeLeft <= 0) {
        this->isGameOver = true;
    }
}

void GameState::renderEndGameMenu()
{
    this->window->draw(this->endGameMenuBackground);

    for (auto& button : endGameMenuButtons) {
        button.render(this->window);
    }
}

void GameState::updateMousePositions()
{
    /*
        Update the mouse positions
    */
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(mousePosWindow);
}

GameState::GameState() {}

GameState::GameState(sf::RenderWindow* window, StateManager* stateManager, sf::Font& font) : State(window, stateManager)
{
    this->font = font;
    this->initBackground();
    this->initVariable();
    this->initBranches();
    this->initText();
    this->initTimer();
    this->initEndGameMenu();
}

void GameState::handleInput()
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (!this->mouseHeld) {
            this->mouseHeld = true;

            if (this->endGameMenuButtons[0].getGlobalBounds().contains(this->mousePosView)) {
                this->stateManager->setState(std::make_unique<GameState>(this->window, this->stateManager, this->font));
            }
            else if (this->endGameMenuButtons[1].getGlobalBounds().contains(this->mousePosView)) {
                this->stateManager->setState(std::make_unique<MenuState>(this->window, this->stateManager, this->font));
            }
        }
    }
    else {
        this->mouseHeld = false;
    }
}

void GameState::update()
{
    this->updateMousePositions();
    if (!isGameOver) {
        this->updateText();
        this->updateTimer();
        this->updateTimerSizeDecay();
        this->checkTimeOver();
    }
}

void GameState::render()
{
    this->window->draw(this->backgroundSprite);

    for (auto &branch : this->branches)
    {
        branch.render(this->window);
    }
    this->lumberjack.render(this->window);

    this->window->draw(this->timer);
    this->window->draw(this->scoreText);

    if (isGameOver) {
        this->renderEndGameMenu();
    }

    // this draws a red line in the middle to help with positioning
    sf::RectangleShape rect(sf::Vector2f(1, 800));
    rect.setFillColor(sf::Color::Red);
    rect.setPosition(this->window->getSize().x / 2 - rect.getSize().x / 2, 0);
    this->window->draw(rect);
    ///
}

void GameState::handleEvent(sf::Event event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (!isGameOver) {
            if (event.key.scancode == sf::Keyboard::Scan::Left)
            {
                this->lumberjack.moveLeft();
                if (!this->checkCollision()) {
                    ++this->score;
                }
                else {
                    this->isGameOver = true;
                }
                this->updateBranches();
                this->resetTimer();
            }
            if (event.key.scancode == sf::Keyboard::Scan::Right)
            {
                this->lumberjack.moveRight();
                if (!this->checkCollision()) {
                    ++this->score;
                }
                else {
                    this->isGameOver = true;
                }
                this->updateBranches();
                this->resetTimer();
            }
        }
    }
}