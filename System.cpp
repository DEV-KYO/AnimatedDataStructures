//
// Created by jnmen on 5/30/2024.
//

#include "System.h"

#include "SortingAlgorithms/AnimatedSortAlg.h"

System::System() : moveFactor(1.0f) {
    // Default constructor
    textBox = TextBox();
    list = AnimatedLinkedList();
    sortAlg = AnimatedSortAlg();
    tree = AnimateTrees();
    hashtable = AnimatedHashtable();

    inputMode = EnumInputMode::LINKEDLIST;

    listFunction = static_cast<EnumListFunctions>(static_cast<int>(EnumListFunctions::FIRST) + 1);
    sortFunction = static_cast<EnumSortFunctions>(static_cast<int>(EnumSortFunctions::FIRST) + 1);
    treeFunction = static_cast<EnumTreeFunctions>(static_cast<int>(EnumTreeFunctions::FIRST) + 1);
    hashFunction = static_cast<EnumHashtable>(static_cast<int>(EnumHashtable::FIRST) + 1);

    treeType = static_cast<EnumTree>(static_cast<int>(EnumTree::FIRST) + 1);

    inputModeText.setFont(FontManager::getFont(PIXELGEORGIA));
    inputModeText.setCharacterSize(24);
    inputModeText.setFillColor(sf::Color::White);
    inputModeText.setString("Welcome to the Data Structures Visualizer");

    inputModeText.setPosition(10, WINDOW_SIZE.y - 30);

    std::cout << "SYSTEM INITIALIZED"   << std::endl
              << "~~~~~~~~~~~~~~~~~~"   << std::endl;

    SLEEP_TIME = 100.0f;


    //FOR TESTING//
    // testNode.setPosition({300,400});

}

void System::Event(sf::RenderWindow& window, sf::Event& event) {

    //switch statement that determines what type of event is happening
    //Events can be anything from closing the window to pressing a key
    switch (event.type)
    {
        //Close window
        case sf::Event::Closed:
            window.close();
            break;

        //Mouse Button Pressed
        case sf::Event::MouseButtonPressed:
            std::cout << "Mouse Button Pressed" << std::endl;

            //This calls the addEventHandler function in the TextBox class
            // textBox.addEventHandler(window, event);

            tree.eventHandler(window,event);
            std::cout << "TREE: " << enumToString(tree.getType()) << std::endl;

            break;

        case sf::Event::MouseWheelScrolled:

            list.eventHandler(window, event);
            sortAlg.eventHandler(window, event);
            hashtable.eventHandler(window, event);
            tree.eventHandler(window, event);

            break;

        //Key Pressed
        case sf::Event::KeyPressed:

            //Every time a key is pressed, a new event is added to the history
            //History will eventually be expanded to include more than just key presses
            History::EventHistory(window, event);

            //This switch statement will determine what key was pressed
            handleKey(window, event);
            break;

        // This event is triggered when text is entered
        case sf::Event::TextEntered:
            if (std::isdigit(static_cast<char>(event.text.unicode)) || event.text.unicode == 32) {
                textBox.addEventHandler(window, event);
            }
            break;
    }
}

void System::Update() {
    // Update the system
    textBox.update();
    switch(inputMode) {
        case EnumInputMode::LINKEDLIST:
            inputModeText.setString(enumToString(listFunction));
            list.update();
            break;
        case EnumInputMode::SORTING:
            inputModeText.setString(enumToString(sortFunction));
            sortAlg.update();
            break;
        case EnumInputMode::TREES:
            inputModeText.setString(enumToString(treeFunction));
            tree.update();
            break;
        case EnumInputMode::HASHTABLE:
            inputModeText.setString(enumToString(hashFunction));
            hashtable.update();
            break;
        default:
            std::cerr << "NO DATASTRUCTURE TO UPDATE" << std::endl;
    }

}

void System::Draw(sf::RenderWindow& window) {
    // Draw the system
    switch (inputMode) {
        case EnumInputMode::LINKEDLIST:
            // Draw the linked list
                list.draw(window, sf::RenderStates::Default);
            break;
        case EnumInputMode::SORTING:
            // Draw the sorting algorithm
                sortAlg.draw(window, sf::RenderStates::Default);
            break;
        case EnumInputMode::TREES:
            tree.draw(window, sf::RenderStates::Default);
            break;
        case EnumInputMode::HASHTABLE:
            hashtable.draw(window, sf::RenderStates::Default);
            break;

        default:
            std::cerr << "NO DATASTRUCTURE TO DISPLAY" << std::endl;
    }
    window.setView(window.getDefaultView());
    window.draw(textBox);
    window.draw(inputModeText);
}

///////////////////////////////////////////////////////////////////////////
///              -----------------------------------                     //
///                    SYSTEM HANDLER FUNCTIONS                          //
///              -----------------------------------                     //
///////////////////////////////////////////////////////////////////////////

//FUNCTIONS TO HANDLE KEY PRESSES

void System::handleMouseWheelScrolled(sf::RenderWindow &window, sf::Event &event) {

    switch(inputMode) {
        case EnumInputMode::LINKEDLIST:
            list.eventHandler(window, event);
            break;
        case EnumInputMode::SORTING:
            sortAlg.eventHandler(window, event);
            break;
        case EnumInputMode::TREES:
            tree.eventHandler(window, event);
            break;
        case EnumInputMode::HASHTABLE:
            hashtable.eventHandler(window, event);
            break;
        default:
            std::cerr << "NO DATASTRUCTURE TO ZOOM" << std::endl;
    }
}

void System::handleKey(sf::RenderWindow &window, sf::Event &event) {
    switch(event.key.code) {

        //Enter key
        case sf::Keyboard::Tab:
            //Change the input mode
            handleTab();
            break;

        //Change function mode
        case sf::Keyboard::Up:
            //Change the list function up
            handleUp();
            break;

        case sf::Keyboard::Down:
            //Change the list function down
            handleDown();
            break;

        case sf::Keyboard::Return:
            handleReturn(window, event);
            break;

        //Backspace key
        case sf::Keyboard::BackSpace:
            textBox.removeLetter();
            data = textBox.getStringOfLetters();
            break;

        //Escape key
        case sf::Keyboard::Escape:
            window.close();
            break;

        case sf::Keyboard::Add:
            SLEEP_TIME -= 10.0f;
            break;

        case sf::Keyboard::Subtract:
            SLEEP_TIME += 10.0f;
            break;
    }
}

void System::handleTab() {
    // Handle the tab key
    // Cast the current EnumInputMode to int and increment it
    int nextMode = static_cast<int>(inputMode) + 1;

    // If the incremented value exceeds the number of EnumInputMode values, reset it to the first one
    if (nextMode == static_cast<int>(EnumInputMode::LAST)) {
        nextMode = static_cast<int>(EnumInputMode::FIRST) + 1;
    }

    // Cast the incremented (or reset) value back to EnumInputMode and assign it to inputMode
    inputMode = static_cast<EnumInputMode>(nextMode);

    std::cout << "~MODE: " << enumToString(inputMode) << std::endl;
    switch(inputMode) {
        case EnumInputMode::LINKEDLIST:
            std::cout << "~" << enumToString(listFunction) << std::endl;
            break;
        case EnumInputMode::SORTING:
            std::cout << "~" << enumToString(sortFunction) << std::endl;
            break;
        case EnumInputMode::TREES:
            std::cout << "~" << enumToString(treeType) << std::endl;
            break;
        case EnumInputMode::HASHTABLE:
            std::cout << "~" << enumToString(hashFunction) << std::endl;
            break;
        default:
            std::cerr << "UNKNOWN INPUTMODE" << std::endl;
    }
}

void System::handleUp() {
    int prevList = static_cast<int>(listFunction) - 1;
    int prevSort = static_cast<int>(sortFunction) - 1;
    int prevTree = static_cast<int>(treeFunction) - 1;
    int prevHash = static_cast<int>(hashFunction) - 1;

    switch (inputMode) {
        case EnumInputMode::LINKEDLIST:
            // Change the list function
            if(prevList == static_cast<int>(EnumListFunctions::FIRST)) {
                prevList = static_cast<int>(EnumListFunctions::LAST) - 1;
            }
            listFunction = static_cast<EnumListFunctions>(prevList);
            std::cout << "~" << enumToString(listFunction) << std::endl;
            break;

        case EnumInputMode::SORTING:
            // Change the sorting algorithm
            if(prevSort == static_cast<int>(EnumSortFunctions::FIRST)) {
                prevSort = static_cast<int>(EnumSortFunctions::LAST) - 1;
            }
            sortFunction = static_cast<EnumSortFunctions>(prevSort);
            std::cout << "~" << enumToString(sortFunction) << std::endl;
            break;

        case EnumInputMode::TREES:
            if(prevTree == static_cast<int>(EnumTreeFunctions::FIRST)) {
                prevTree = static_cast<int>(EnumTreeFunctions::LAST) - 1;
            }
            treeFunction = static_cast<EnumTreeFunctions>(prevTree);
            std::cout << "~" << enumToString(treeFunction) << std::endl;
            break;

        case EnumInputMode::HASHTABLE:
            if(prevHash == static_cast<int>(EnumHashtable::FIRST)) {
                prevHash = static_cast<int>(EnumHashtable::LAST) - 1;
            }
            hashFunction = static_cast<EnumHashtable>(prevHash);
            std::cout << "~" << enumToString(hashFunction) << std::endl;
            break;

        default:
            std::cerr << "Unknown InputMode" << std::endl;
    }
}

void System::handleDown() {
    int nextList = static_cast<int>(listFunction) + 1;
    int nextSort = static_cast<int>(sortFunction) + 1;
    int nextTree = static_cast<int>(treeFunction) + 1;
    int nextHash = static_cast<int>(hashFunction) + 1;

    switch(inputMode) {
        case EnumInputMode::LINKEDLIST:
            if(nextList == static_cast<int>(EnumListFunctions::LAST)) {
                nextList = static_cast<int>(EnumListFunctions::FIRST) + 1;
            }
            listFunction = static_cast<EnumListFunctions>(nextList);
            std::cout << "~" << enumToString(listFunction) << std::endl;
            break;

        case EnumInputMode::SORTING:
            if(nextSort == static_cast<int>(EnumSortFunctions::LAST)) {
                nextSort = static_cast<int>(EnumSortFunctions::FIRST) + 1;
            }
            sortFunction = static_cast<EnumSortFunctions>(nextSort);
            std::cout << "~" << enumToString(sortFunction) << std::endl;
            break;

        case EnumInputMode::TREES:
            if(nextTree == static_cast<int>(EnumTreeFunctions::LAST)) {
                nextTree = static_cast<int>(EnumTreeFunctions::FIRST) + 1;
            }
            treeFunction = static_cast<EnumTreeFunctions>(nextTree);

            std::cout << "~" << enumToString(treeFunction) << std::endl;
            break;

        case EnumInputMode::HASHTABLE:
            if(nextHash == static_cast<int>(EnumHashtable::LAST)) {
                nextHash = static_cast<int>(EnumHashtable::FIRST) + 1;
            }
            hashFunction = static_cast<EnumHashtable>(nextHash);
            std::cout << "~" << enumToString(hashFunction) << std::endl;
            break;

        default:
            std::cerr << "Unknown InputMode" << std::endl;
    }
}

void System::handleReturn(sf::RenderWindow &window, sf::Event &event) {
    // Handle the return key
    data = textBox.getStringOfLetters();
    switch(inputMode) {
        case EnumInputMode::LINKEDLIST:
            switch(listFunction) {
                case EnumListFunctions::PUSH_BACK:
                    if(!data.empty() && data != " ") {
                        list.push_back(data);
                    }
                    break;

                case EnumListFunctions::PUSH_FRONT:
                    list.push_front(data);
                    break;

                case EnumListFunctions::POP_BACK:
                    list.pop_back();
                    break;

                case EnumListFunctions::POP_FRONT:
                    list.pop_front();
                    break;

                case EnumListFunctions::CLEAR:
                    list.clear();
                    break;
            }
            std::cout << "LIST: " << enumToString(listFunction) << std::endl;
        break;

        case EnumInputMode::SORTING:
            // Handle the sorting algorithm
            switch(sortFunction) {
                case EnumSortFunctions::QUICKSORT:
                    sortAlg.sort(sortFunction);
                    break;

                case EnumSortFunctions::MERGESORT:
                    sortAlg.sort(sortFunction);
                    break;

                case EnumSortFunctions::PUSH_BACK:
                    if(!data.empty() && data != " ") {
                        sortAlg.push_back(data);
                    }
                    break;

                case EnumSortFunctions::PUSH_FRONT:
                    if(!data.empty() && data != " ") {
                        sortAlg.push_front(data);
                    }
                    break;

                case EnumSortFunctions::POP_BACK:
                    sortAlg.pop_back();
                    break;

                case EnumSortFunctions::POP_FRONT:
                    sortAlg.pop_front();
                    break;

                case EnumSortFunctions::CLEAR:
                    sortAlg.clear();
                    break;

                default:
                    std::cerr << "NO SORTING ALGORITHM SELECTED" << std::endl;
            }
            std::cout << "SORT: " << enumToString(sortFunction) << std::endl;
            break;

        case EnumInputMode::TREES:
            // Handle the tree
            switch(treeFunction) {
                case EnumTreeFunctions::PUSH_BACK:
                    if(!data.empty() && data != " ") {
                        tree.push_back(data);
                    }
                    break;

                case EnumTreeFunctions::POP_BACK:
                    tree.pop_back();
                break;

                case EnumTreeFunctions::CLEAR:
                    tree.clear();
                    break;
            }

            tree.eventHandler(window, event);
            std::cout << "TREE: " << enumToString(tree.getType()) << std::endl;
            break;

        case EnumInputMode::HASHTABLE:
            switch(hashFunction) {
                case EnumHashtable::PUSH_BACK:
                    std::cout << "PUSHING BACK" << std::endl;
                    if(!data.empty() && data != " ") {

                        hashtable.pushData(data);
                    }
                    hashtable.createHashtable();
                    break;
                case EnumHashtable::CLEAR:
                    hashtable.clear();
                    break;
                default:
                    std::cerr << "NO HASH FUNCTION SELECTED" << std::endl;
            }
            std::cout << "HASHTABLE: " << enumToString(hashFunction) << std::endl;
            break;
    }
    textBox.clear();
    data = "";
}



///////////////////////////////////////////////////////////////////////////
///              -----------------------------------                     //
///                    SYSTEM ENUM TO STRING                             //
///              -----------------------------------                     //
///////////////////////////////////////////////////////////////////////////


//FUNCTIONS TO CONVERT ENUMS TO STRINGS
std::string System::enumToString(const EnumInputMode& inputMode) {
    switch(inputMode) {
        case EnumInputMode::LINKEDLIST:
            return "LINKEDLIST";
        case EnumInputMode::SORTING:
            return "SORTING";
        case EnumInputMode::TREES:
            return "TREES";
        case EnumInputMode::HASHTABLE:
            return "HASHTABLE";
        default:
            return "UNKNOWN";
    }
}

std::string System::enumToString(const EnumListFunctions& listFunction) {
    switch(listFunction) {
        case EnumListFunctions::PUSH_BACK:
            return "PUSH_BACK";
        case EnumListFunctions::PUSH_FRONT:
            return "PUSH_FRONT";
        case EnumListFunctions::POP_BACK:
            return "POP_BACK";
        case EnumListFunctions::POP_FRONT:
            return "POP_FRONT";
        case EnumListFunctions::CLEAR:
            return "CLEAR";
        default:
            return "UNKNOWN";
    }
}

std::string System::enumToString(const EnumSortFunctions& sortFunction) {
    switch(sortFunction) {
        case EnumSortFunctions::QUICKSORT:
            return "QUICKSORT";
        case EnumSortFunctions::MERGESORT:
            return "MERGESORT";
        case EnumSortFunctions::PUSH_BACK:
            return "PUSH_BACK";
        case EnumSortFunctions::PUSH_FRONT:
            return "PUSH_FRONT";
        case EnumSortFunctions::POP_BACK:
            return "POP_BACK";
        case EnumSortFunctions::POP_FRONT:
            return "POP_FRONT";
        case EnumSortFunctions::CLEAR:
            return "CLEAR";
        default:
            return "UNKNOWN";
    }
}

std::string System::enumToString(const EnumTree& treeType) {
    switch(treeType) {
        case EnumTree::BST:
            return "BINARY";
        case EnumTree::AVL:
            return "AVL";
        case EnumTree::HEAP:
            return "HEAP";
        default:
            return "UNKNOWN";
    }
}

std::string System::enumToString(const EnumHashtable& hashFunction) {
    switch(hashFunction) {
        case EnumHashtable::PUSH_BACK:
            return "PUSH_BACK";
        case EnumHashtable::CLEAR:
            return "CLEAR";
        default:
            return "UNKNOWN";
    }
}

std::string System::enumToString(const EnumTreeFunctions& treeFunction) {
    switch(treeFunction) {
        case EnumTreeFunctions::FIRST:
            return "FIRST";

        case EnumTreeFunctions::PUSH_BACK:
            return "PUSH_BACK";
        // case EnumTreeFunctions::PUSH_FRONT:
        //     return "PUSH_FRONT";
        case EnumTreeFunctions::POP_BACK:
            return "POP_BACK";
        case EnumTreeFunctions::CLEAR:
            return "CLEAR";

        case EnumTreeFunctions::LAST:
            return "LAST";
        default:
            return "UNKNOWN";
    }
}