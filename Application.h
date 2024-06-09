//
// Created by Jonas Mendoza on 4/26/24.
//

#ifndef APPLICATION_H
#define APPLICATION_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>

#include "Settings.h"
#include "System.h"
#include "Drawables/EnumDrawables/EnumDrawables.h"
#include "History/History.h"


class Application {
private:
    sf::RenderWindow window;        //This is the window that will be displayed
    System system;                  //This is the system that will be displayed


public:
    Application();

    //Runs the application & main loop
    //It will run a while loop that will process events, update, and render
    void Run();

    //Function called to draw function of any object
    //that needs to be drawn on the window
    void Draw();

    //This function processes events that are happening in the window
    void ProcessEvents();

    //This function updates the state of the application
    void Update();

    //Renders all objects to the window
    void Render();
};


#endif //TEXT_INPUT_PROJECT_APPLICATION_H
