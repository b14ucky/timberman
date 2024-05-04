#include "App.h"

// private functions
void App::initWindow()
{
    /*
        Initializes the window of the game. Sets its size, title and frame rate limit.
    */
    this->videoMode.width = 480;
    this->videoMode.height = 800;
    this->window = new sf::RenderWindow(this->videoMode, "Timberman", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(144);
}

void App::initFont()
{
    /*
        Initializes the font of the game. Loads the font from the file.
    */
    if (!this->font.loadFromFile("./assets/fonts/" /*CHANGE TO ACTUAL FONT PATH*/))
    {
        std::cout << "ERROR::APP::INITFONT::Failed to load font!" << std::endl;
    }
}

void App::update()
{
    this->stateManager->update();
}

void App::render()
{
    /*
        Renders current state objects to the window. Clears the window at the beginning and sets the background color to black.
    */
    this->window->clear(sf::Color::White);
    this->stateManager->render();
    this->window->display();
}

// constructors/destructors/run
App::App()
{
    /*
        The constructor of the App class. Calls the initWindow function to initialize the window.
    */
    this->stateManager = new StateManager();
    this->initWindow();
    this->initFont();
}

App::~App()
{
    /*
        The destructor of the App class. Deletes the window pointer.
    */
    delete this->window;
    delete this->stateManager;
}

void App::run()
{
    /*
        The run function of the App class. Runs the game loop.
    */
    this->stateManager->setState(std::make_unique<GameState /*!!! CHANGE TO MENU STATE AFTER IMPLEMENTING IT !!!*/>(this->window, this->stateManager, this->font));

    while (this->window->isOpen())
    {
        while (this->window->pollEvent(this->event))
        {
            if (this->event.type == sf::Event::Closed)
            {
                this->window->close();
            }
        }
        this->update();
        this->render();
    }
}