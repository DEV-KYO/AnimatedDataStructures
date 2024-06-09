//
// Created by Jonas Mendoza on 4/26/24.
//

#include "Application.h"

#include "KeyboardShortcuts/KeyboardShortcuts.h"

Application::Application() : system() {

    //Create the window using given resolution and title
    window.create(sf::VideoMode(
            WINDOW_SIZE.x,
            WINDOW_SIZE.y
            ), "Text Input Project");

    //Set the framerate limit to 60
    window.setFramerateLimit(60);

}


void Application::Run() {

    std::cout   << "APPLICATION STARTING"
                << std::endl;

    //Main loop of the application
    while (window.isOpen())
    {
        ProcessEvents();
        Update();
        Render();
    }

    std::cout   << std::endl
                << "APPLICATION CLOSING"
                << std::endl;

}

void Application::ProcessEvents() {

    //The event loop that will process all events that are happening in the window
    //This loop will run as long as there are events to process
    sf::Event event;
    while(window.pollEvent(event))
    {
        system.Event(window, event);
    }
}

void Application::Update()
{
    system.Update();
}

void Application::Render() {
    window.clear({sf::Color::Black});
    Draw();
    window.display();
}

void Application::Draw() {
    system.Draw(window);
}