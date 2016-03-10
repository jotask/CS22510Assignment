#ifndef CS22510_DISPLAY_H
#define CS22510_DISPLAY_H


#include <SFML/Graphics/RenderWindow.hpp>
#include "Simulation.h"

class Display {
public:
    Display(const configuration&, Simulation&);
    ~Display();

    void loop();

private:

    bool isDebug;
    bool saveScreenToImage;

    int screenshot_num;

    sf::RenderWindow* window;
    Simulation* simulation;

    void update();
    void render();

};


#endif //CS22510_DISPLAY_H
