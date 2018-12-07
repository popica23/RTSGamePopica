#ifndef GAME_H
#define GAME_H

#include "scriptReader.h"
#include "level.h"
#include "texture_manager.h"
#include "game_state.hpp"
#include "unit.hpp"
#include "map.h"


#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window.hpp>

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <pthread.h>

#define NUM_THREADS 2


class Game{

private:


    pthread_t threads[NUM_THREADS];

    sf::Event event;
    sf::RenderWindow window;
    std::vector<sf::Text> menuText;


    Map myMap;

    int tileId;

    scriptReader script;
    Level level;

    sf::String title = "WARLORDS GATE";

    std::vector <std::string> slideTitle;
    int menuIndex = 0;
    std::vector <int> ButtonIndex;
    //std::vector <std::string> ButtonText;
    sf::Texture ButtonDesign;

    int screenWidth;
    int screenHeight;

    sf::Font font;

    std::vector<sf::Sprite*> tile;

    int viewX;
    int viewY;

    int speedViewX = 0;
    int speedViewY = 0;

    sf::View gameView;

    sf::Clock clock;
    sf::Time time;
    float dt = 0;
    int gameSpeed = 200;


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
    void loadTextures();
    void loadFont();
    void loadMenuText(sf::Font&, std::string, int, int, int, sf::Text *tex);

    void setScreen(int, int, sf::String);
    void run();

    int getScreenW(){return screenWidth;}
    int getScreenH(){return screenHeight;}
    std::string getScreenTitle(){return title;}

    sf::Texture getButtonTexture(){return ButtonDesign;}

    void menu();

    void setButtonsText();

    void stateMachine();

    void handleEvents();

    void moveCamera();

    void updateCamera();

    Texture_manager texmgr;

    sf::Sprite background;

    bool isAnyKeyPressed();

    enum GameStates{
    STATE_START = 0,
    STATE_MENU = 1,
    STATE_OPTIONS = 2,
    STATE_SETTINGS = 3,
    STATE_LEVEL = 4,
    STATE_GAME = 5
    //.. etc
    };

    //void pushState(GameState* state);


};





#endif // GAME_H

