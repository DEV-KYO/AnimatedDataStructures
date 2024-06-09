cmake_minimum_required(VERSION 3.28)
project(AnimatedDataStructures)

set(CMAKE_CXX_STANDARD 17)

add_executable(AnimatedDataStructures
        main.cpp
        System.cpp
        System.h
        Settings.h
        Application.h
        Application.cpp
        System/EnumSystem/EnumInputMode.h
        States/States.h
        States/States.cpp
        States/EnumStates.h
        MouseEvents/MouseEvents.h
        MouseEvents/MouseEvents.cpp
        LinkedList/AnimatedLinkedList.cpp
        LinkedList/AnimatedLinkedList.h
        LinkedList/EnumListFunctions.h
        KeyboardShortcuts/KeyboardShortcuts.cpp
        KeyboardShortcuts/KeyboardShortcuts.h
        History/History.cpp
        History/History.h
        History/HistoryNode.h
        GUIComponents/EventHandler/EventHandler.h
        GUIComponents/snapshot/Snapshot.h
        GUIComponents/snapshot/Snapshot.cpp
        GUIComponents/snapshot/SnapshotInterface.h
        GUIComponents/GUIComponent.h
        Font/EnumFonts.h
        Font/FontManager.cpp
        Font/FontManager.h
        Drawables/Arrowshape/ArrowShape.cpp
        Drawables/Arrowshape/ArrowShape.h
        Drawables/EnumDrawables/EnumDrawables.h
        Drawables/EnumDrawables/EnumDirection.h
        Drawables/NodeShape/NodeShape.cpp
        Drawables/NodeShape/NodeShape.h
        Drawables/TextBox/TextBox.cpp
        Drawables/TextBox/TextBox.h
        Drawables/TextBox/LetterObject.cpp
        Drawables/TextBox/LetterObject.h
        Drawables/Textbox/Label.h
        Drawables/Textbox/Label.cpp
        Drawables/Textbox/Cursor.cpp
        Drawables/Textbox/Cursor.h
        Drawables/TextBox/_Local_Constants.h
        SortingAlgorithms/AnimatedSortAlg.cpp
        SortingAlgorithms/AnimatedSortAlg.h
        SortingAlgorithms/EnumSortFunctions.h
        Drawables/SquareText/SquareText.cpp
        Drawables/SquareText/SquareText.h
        SortingAlgorithms/EnumSortState.h
        Trees/BST.cpp
        Trees/BST.h
        Drawables/CircleText/CircleText.cpp
        Drawables/CircleText/CircleText.h
        Trees/AnimateTrees.cpp
        Trees/AnimateTrees.h
        Node.h
        Trees/EnumTree.h
        Trees/AVL.cpp
        Trees/AVL.h
        Trees/Heap.cpp
        Trees/Heap.h
        Hashtable/Hashtable.h
        Hashtable/HashNode.h
        Hashtable/Hashtable.cpp
        Hashtable/AnimatedHashtable.cpp
        Hashtable/AnimatedHashtable.h
        Hashtable/EnumHashtable.h

)


# CMake SFML Project uses C++17 features
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_EXTENSIONS NO CXX_STANDARD_REQUIRED YES)

# Set SFML_ROOT
set(SFML_ROOT "C:/SFML-2.6.1")

# Set SFML_DIR
set(SFML_DIR "C:/SFML-2.6.1/lib/cmake/SFML")

# Find SFML
find_package(SFML 2.6 COMPONENTS graphics system window REQUIRED)

# Link SFML
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-system sfml-window)

# Install executable
install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION .)
