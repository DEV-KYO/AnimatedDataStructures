//
// Created by Jonas Mendoza on 4/27/24.
//

#ifndef TEXT_INPUT_PROJECT_HISTORY_H
#define TEXT_INPUT_PROJECT_HISTORY_H
#include "HistoryNode.h"
#include <stack>
#include <SFML/Window/Event.hpp>
#include <iostream>

class History : public GUIComponent{
private:
    static std::stack<HistoryNode> stack;                                   // Stack of HistoryNodes
public:
    static void pushHistory(const HistoryNode& snapshot);                   // Pushes a HistoryNode to the stack
    static HistoryNode& topHistory();                                       // Returns the top HistoryNode of the stack
    static void popHistory();                                               // Pops the top HistoryNode of the stack
    static void EventHistory(sf::RenderWindow& window, sf::Event event);    // Processes the event history

};


#endif //TEXT_INPUT_PROJECT_HISTORY_H
