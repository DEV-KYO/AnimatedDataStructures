//
// Created by Jonas Mendoza on 4/27/24.
//

#include "FontManager.h"
std::map<EnumFonts, sf::Font> FontManager::fonts;


void FontManager::loadFont(EnumFonts font) {
    if(!fonts[font].loadFromFile(getFontPath(font)))
        exit(28);
}

std::string FontManager::getFontPath(EnumFonts font) {
    switch(font){
        case PIXELGEORGIA:
            return "../Assets/TextFiles/PixelGeorgia.ttf";
    }
    return "";
}

sf::Font &FontManager::getFont(EnumFonts font) {
    if(fonts.count(font) == 0)
        loadFont(font);
    return fonts[font];
}