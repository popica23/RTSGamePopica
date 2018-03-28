#ifndef GAME_H
#define GAME_H

#include "scriptReader.h"
#include "level.h"


#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window.hpp>

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class Game{

private:

    sf::Event event;
    sf::RenderWindow window;

    std::string myString;

    scriptReader script;
    Level level;

    sf::String title = "title";

    std::vector <std::string> slideTitle;
    int menuIndex = 0;
    std::vector <int> ButtonIndex;
    std::vector <std::string> ButtonText;
    sf::Texture ButtonDesign;

    int screenWidth;
    int screenHeight;

public:

    void loadUnits();
    void loadBuildings();
    void loadHero();
    void loadInput();
    void loadSelect();
    void loadTextArea();
    void loadRadio();
    void loadButton();

    void setScreen(int, int, sf::String);
    void run();

    int getScreenW(){return screenWidth;}
    int getScreenH(){return screenHeight;}
    std::string getScreenTitle(){return title;}

    sf::Texture getButtonTexture(){return ButtonDesign;}

    void menu();

    void setButtonsText();

};


#endif // GAME_H
