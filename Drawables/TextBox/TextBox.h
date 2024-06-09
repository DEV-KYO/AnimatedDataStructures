//
// Created by Jonas Mendoza on 4/28/24.
//

#ifndef TEXT_INPUT_PROJECT_TEXTBOX_H
#define TEXT_INPUT_PROJECT_TEXTBOX_H
#include <vector>

//SFML
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Window/Event.hpp>

//FOLDERS
#include "../../GUIComponents/GUIComponent.h"
#include "../../MouseEvents/MouseEvents.h"
#include "../../History/History.h"
#include "Cursor.h"
#include "Label.h"
#include "LetterObject.h"
#include "../../States/States.h"
#include "../../Font/EnumFonts.h"
#include "../../Font/FontManager.h"
#include "_LOCAL_CONSTANTS.h"
#include "../../KeyboardShortcuts/KeyboardShortcuts.h"



class TextBox : public GUIComponent {

private:
    //Variables
    sf::RectangleShape shape;           //Shape of the text box
    Label label;                        //Label object
    Cursor cursor;                      //Cursor object
    States active;                      //Boolean to check if the text box is active
    Snapshot text_box_snapshot;         //Snapshot of the text box

    //Vectors
    std::vector<LetterObject> letters;  //Vector of letters
    std::vector<std::string> text;


public:
    //Default constructor
    TextBox();

    //GUIComponent functions
    void draw(sf::RenderTarget &window, sf::RenderStates states) const override;    //Draws the text box
    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;       //Adds an event handler to the text box
    void update() override;
    Snapshot& getSnapshot() override;                                               //Returns the snapshot of the text box
    void applySnapshot(const Snapshot& snapshot) override;                          //Applies the snapshot to the text box


    //TextBox functions
    void addLetter(LetterObject addedLetter);
    void removeLetter();

    void clear();

    //Setters
    void setState(ObjectState state);                                               //Sets the state of the text box

    //Getters
    bool isEnabled() const;                                                         //Returns true if the text box is enabled
    sf::FloatRect getLocalBounds() const;                                           //Returns the local bounds of the text box
    sf::FloatRect getGlobalBounds() const;                                          //Returns the global bounds of the text box
    sf::RectangleShape& getShape();                                                 //Returns the shape of the text box
    long getSize() const;                                                           //Returns the size of the text box
    std::vector<std::string> getVectorOfLetters();                                         //Returns the vector of letters
    std::string getStringOfLetters();                                               //Returns the string of letters
    static std::string convertText(const LetterObject &letter) ;                                                        //Returns the text of the text box
};


#endif //TEXT_INPUT_PROJECT_TEXTBOX_H
