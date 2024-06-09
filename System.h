//
// Created by jnmen on 5/30/2024.
//

#ifndef SYSTEM_H
#define SYSTEM_H
#include "Settings.h"

#include "Drawables/Arrowshape/Arrowshape.h"
#include "Drawables/EnumDrawables/EnumDrawables.h"
#include "Drawables/NodeShape/NodeShape.h"
#include "Drawables/TextBox/TextBox.h"
#include "Hashtable/EnumHashtable.h"

#include "LinkedList/AnimatedLinkedList.h"
#include "SortingAlgorithms/AnimatedSortAlg.h"

#include "LinkedList/EnumListFunctions.h"
#include "SortingAlgorithms/EnumSortFunctions.h"
#include "System/EnumSystem/EnumInputMode.h"
#include "Trees/AnimateTrees.h"
#include "Trees/EnumTree.h"


class System {
private:
    float moveFactor; //factor to move the arrow
    TextBox textBox; //text box to display text
    std::vector<std::string> dataVector; //data to display
    std::string data; //string to display
    EnumInputMode inputMode; //mode of input
    EnumListFunctions listFunction; //function of the linked list
    EnumSortFunctions sortFunction; //function of the sorting algorithm
    EnumTree treeType; //type of tree
    EnumHashtable hashFunction; //hash function


    //FOR TESTING//
    // NodeShape testNode; //node to test
    AnimatedLinkedList list; //linked list to test
    AnimatedSortAlg sortAlg; //sorting algorithm to test
    AnimateTrees tree; //trees to test

public:
    System();
    void Event(sf::RenderWindow& window, sf::Event& event); //function to update the system
    void Update(); //function to update the system
    void Draw(sf::RenderWindow& window); //function to draw the system


    void handleKey(sf::RenderWindow &window, sf::Event& event); //handle the key Pressed
    void handleTab(); //handle the tab key
    void handleUp(); //handle the up and down keys
    void handleDown(); //handle the up and down keys
    void handleReturn(sf::RenderWindow &window); //handle the return key


    //functions to convert enum to string
    static std::string enumToString(const EnumListFunctions& function);
    static std::string enumToString(const EnumInputMode& inputMode);
    static std::string enumToString(const EnumSortFunctions& sortFunction);
    static std::string enumToString(const EnumTree& treeType);


};



#endif //SYSTEM_H
