#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "Display.h"

/**
 * Constructor for this class.
 *
 * @arg configuration: Reference to the configuration struct
 * @arg simulation: Reference to the simulation manager
 */
Display::Display(const configuration& config, Simulation& sim) : isDebug(config.debug),
                                                                 saveScreenToImage(config.saveScreenShoots) {

    this -> simulation = &sim;

    this -> window = new sf::RenderWindow(sf::VideoMode(config.displayWidth, config.displayHeight),
                                          config.displayTitle, sf::Style::Close | sf::Style::Titlebar);

    this -> screenshot_num = 0;

}

/**
 * Destructor for this class delete the window from the heap
 */
Display::~Display() {
    delete(window);
}

/**
 * Loop for update and render the simulation
 */
void Display::loop() {

    // keep looping until the windows get close
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

/**
 * Update all the logic for the simulation.
 */
void Display::update() {

    // Check if the simulation has finished. If is finished exit the function
    if(simulation -> isFinishedSimulation()){
        return;
    }

    // If the simulation has simulated and we want store the frame
    if(simulation -> simulateStep() && saveScreenToImage){

        // Make a capture of the screen and stored it
        sf::Image image = window -> capture();
        std::stringstream filename;
        filename << "data/screenshot_" << screenshot_num++ << ".png";
        image.saveToFile(filename.str());
    }

}

/**
 * Render the simulation
 */
void Display::render() {

    // Clear the window
    window -> clear(sf::Color::Black);

    // Get a pointer to the world. For quicker access
    World* world;
    world = simulation->getWorld();

    // Get whe width and height of the world
    unsigned int WORLD_WIDTH = world -> WORLD_WIDTH;
    unsigned int WORLD_HEIGHT = world -> WORLD_HEIGHT;

    // Variable for know how the size of the cell we want to draw on screen
    const sf::Vector2u& sizeWindow = window->getSize();
    int width = (sizeWindow.x / WORLD_WIDTH);
    int height = (sizeWindow.y / WORLD_HEIGHT);

    // Get the information of each cell and draw it on the screen
    for(unsigned int y = 0; y < WORLD_HEIGHT; y++){
        for(unsigned int x = 0; x < WORLD_WIDTH; x++){

            // Get the value from the current cell
            util::Cell cell = world -> getValueAt(y, x);

            // Create a rectangle
            sf::RectangleShape rectangle;

            // Set the size of the triangle
            rectangle.setSize(sf::Vector2f(width, height));

            // Know which type of cell is, and choose a color
            switch (cell){
                case util::Cell::OBSTACLE:
                    rectangle.setFillColor(sf::Color::Black);
                    break;
                case util::Cell::ROBOT:
                    rectangle.setFillColor(sf::Color::Red);
                    break;
                default:
                case util::Cell::EMPTY:
                    rectangle.setFillColor(sf::Color::White);
                    break;
            }

            // If is debug draw the outline for the rectangle
            if(isDebug) {
                rectangle.setOutlineColor(sf::Color::Red);
                rectangle.setOutlineThickness(1);
            }

            // Set the position of the cell on the screen
            rectangle.setPosition(y * width, x * height);
            window -> draw(rectangle);

        }
    }

    // Draw everything on the screen
    window -> display();
}
