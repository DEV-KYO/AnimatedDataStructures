#include <iostream>

#include "Application.h"


int main() {
    //container class that holds the window and the text box
    Application app;

    //run the application
    app.Run();

    //end of program
    std::cout   << std::endl
                << std::endl
                << std::endl
                << "PROGRAM END" << std::endl;

    return 0;
}
