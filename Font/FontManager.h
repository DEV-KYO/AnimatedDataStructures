//
// Created by Jonas Mendoza on 4/27/24.
//

#ifndef TEXT_INPUT_PROJECT_FONTMANAGER_H
#define TEXT_INPUT_PROJECT_FONTMANAGER_H
#include <map>
#include <SFML/Graphics/Font.hpp>
#include "EnumFonts.h"

class FontManager {
private:
    static std::map<EnumFonts, sf::Font> fonts;         // Map of EnumFonts to sf::Font
    static void loadFont(EnumFonts font);               // Loads a font from a file
    static std::string getFontPath(EnumFonts font);     // Returns the path of the font file

public:
    static sf::Font& getFont(EnumFonts font);           // Returns the font
};


#endif //TEXT_INPUT_PROJECT_FONTMANAGER_H
