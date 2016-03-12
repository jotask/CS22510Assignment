#ifndef CS22510_DISPLAY_H
#define CS22510_DISPLAY_H

#include <SFML/Graphics/RenderWindow.hpp>
#include "Simulation.h"

/**
 * Class that create and handle the display for show the simulation
 */
class Display {
public:

    //Constructor for this class.
    Display(const configuration&, Simulation&);

    // Destructor for this class
    ~Display();

    // This function create a loop for update the simulation, read and handle events from
    // the display and render the simulation
    void loop();

private:

    // Boolean for display on the screen debug information
    bool isDebug;

    // Boolean for know if we need to store each render step result to an image
    bool saveScreenToImage;

    // Know how many screenshoots has been stored. This number is incremented each time an
    // screen has been saved and is used to the image filename
    int screenshot_num;

    // A pointer to the RendererWindow
    sf::RenderWindow* window;

    // A pointer to the simulation
    Simulation* simulation;

    // Update the logic for the simulation
    void update();

    // Render the simulation
    void render();

};


#endif //CS22510_DISPLAY_H
