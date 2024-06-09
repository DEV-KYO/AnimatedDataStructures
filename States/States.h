//
// Created by Jonas Mendoza on 4/26/24.
//

#ifndef TEXT_INPUT_PROJECT_STATES_H
#define TEXT_INPUT_PROJECT_STATES_H
#include <map>
#include "EnumStates.h"
#include "States.h"


class States {
private:
    std::map<ObjectState, bool> states; // Map of states

public:
    States();

    [[nodiscard]] bool getState() const; // Get state of object
    void disableState(); // Disable state of object
    void enableState(); // Enable state of object
    void toggleState(); // Toggle state of object

};


#endif //TEXT_INPUT_PROJECT_STATES_H
