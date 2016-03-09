#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "Display.h"

bool Display::isDebug = false;

Display::Display(unsigned int width, unsigned int height, const char* title, unsigned int fps, Simulation& sim) {

    this -> simulation = &sim;

    this -> window = new sf::RenderWindow(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
    this -> window -> setFramerateLimit(fps);

}

Display::~Display() {
    delete(window);
}


void Display::loop() {
    while(window -> isOpen()) {
        // Handle events
        sf::Event event;
        while(window -> pollEvent(event)){
            switch (event.type){
                case sf::Event::Closed:
                    window -> close();
                    break;
                default:
                    break;

            }
        }

        // Update the logic
        update();

        // Render Everything
        render();
    }

}

void Display::update() {

    if(simulation -> isFinishedSimulation()){
        return;
    }

    simulation -> simulateStep();

}

void Display::render() {

    window -> clear(sf::Color::Black);

    const sf::Vector2u& sizeWindow = window->getSize();
    int width = (sizeWindow.x / World::WORLD_WIDTH);
    int height = (sizeWindow.y / World::WORLD_HEIGHT);

    World* world = this -> simulation -> getWorld();
    for(int i = 0; i < World::WORLD_HEIGHT; i++){
        for(int j = 0; j < World::WORLD_WIDTH; j++){
            Util::Cell cell = world -> getValueAt(i, j);

            sf::RectangleShape rectangle;
            rectangle.setSize(sf::Vector2f(width, height));

            switch (cell){
                case Util::Cell::OBSTACLE:
                    rectangle.setFillColor(sf::Color::Black);
                    break;
                case Util::Cell::ROBOT:
                    rectangle.setFillColor(sf::Color::Red);
                    break;
                default:
                case Util::Cell::EMPTY:
                    rectangle.setFillColor(sf::Color::White);
                    break;
            }

            if(isDebug) {
                rectangle.setOutlineColor(sf::Color::Red);
                rectangle.setOutlineThickness(1);
            }

            rectangle.setPosition(i * width, j * height);
            window -> draw(rectangle);
        }
    }

    window -> display();
}

void Display::setInterval() {

}
