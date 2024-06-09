//
// Created by Jonas Mendoza on 4/26/24.
//

#ifndef TEXT_INPUT_PROJECT_GUICOMPONENT_H
#define TEXT_INPUT_PROJECT_GUICOMPONENT_H
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include "EventHandler/EventHandler.h"
#include "Snapshot/SnapshotInterface.h"
#include "../States/States.h"

class GUIComponent  :   public EventHandler,        //Inherits from EventHandler
                        public SnapshotInterface,   //Inherits from SnapshotInterface
                        public States,              //Inherits from States
                        public sf::Drawable,        //Inherits from sf::Drawable
                        public sf::Transformable {  //Inherits from sf::Transformable

};


#endif //TEXT_INPUT_PROJECT_GUICOMPONENT_H
