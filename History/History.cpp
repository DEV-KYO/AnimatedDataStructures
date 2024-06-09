//
// Created by Jonas Mendoza on 4/27/24.
//

#include "History.h"

#include "../KeyboardShortcuts/KeyboardShortcuts.h"

std::stack<HistoryNode> History::stack; // Stack of HistoryNodes

void History::pushHistory(const HistoryNode &snapshot) {
    stack.push(snapshot);
}

HistoryNode &History::topHistory() {
    return stack.top();
}

void History::popHistory() {
    stack.pop();
}

void History::EventHistory(sf::RenderWindow &window, sf::Event event) {
    // If the user presses the undo key, undo the last action
    if(sf::Event::KeyPressed && KeyboardShortcuts::isUndo() && !stack.empty()) {
            std::cout << "Undoing" << std::endl;
            HistoryNode node = stack.top();
            stack.pop();
            node.component->applySnapshot(node.snapshot);
    }
}
