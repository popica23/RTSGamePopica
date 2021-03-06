#ifndef GAME_H
#define GAME_H

#include "scriptReader.h"
#include "level.h"
#include "texture_manager.h"
#include "game_state.h"


#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window.hpp>

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class GameState;

class Game{

private:


    sf::Event event;
    sf::RenderWindow window;

    std::map<std::string, sf::Texture> textures;

    int tileId;

    scriptReader script;
    Level level;

    sf::String title = "Gate Warlord";

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
    int tileRender();

    void setScreen(int, int, sf::String);
    void run();

    int getScreenW(){return screenWidth;}
    int getScreenH(){return screenHeight;}
    std::string getScreenTitle(){return title;}

    sf::Texture getButtonTexture(){return ButtonDesign;}

    void menu();

    void setButtonsText();

    std::stack<GameState*> states;
    Texture_manager texmgr;
    sf::Sprite background;

    void pushState(GameState* state);

};


#endif // GAME_H
