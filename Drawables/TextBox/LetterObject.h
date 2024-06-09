//
// Created by Jonas Mendoza on 4/26/24.
//

#ifndef TEXT_INPUT_PROJECT_LETTEROBJECT_H
#define TEXT_INPUT_PROJECT_LETTEROBJECT_H

#include <iostream>

//SFML
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>

//FOLDERS
#include "../../GUIComponents/GUIComponent.h"
#include "../../MouseEvents/MouseEvents.h"
#include "../../Font/FontManager.h"
#include "_LOCAL_CONSTANTS.h"

class LetterObject : 	public sf::Drawable,
						public sf::Transformable
						 {

private:
    sf::Text text;

public:
    LetterObject(); //Constructor

//From GUIComponent
    // from EventHandler
    void update();
    //Render
    //from the sf::Drawable class
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;

	//Getters and Setters
	void setCharacter(char typedChar);
	char getCharacter() const;

	sf::Vector2f getPosition();
	void setPosition(const sf::Vector2f& position);

	//Set the state of the object
	void setState(ObjectState state);

	//Get the state of the object
	sf::FloatRect getLocalBounds() const;

};


#endif //TEXT_INPUT_PROJECT_TEXTINPUT_H
