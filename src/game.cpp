#include "game.hpp"
#include "tile.h"



void Game::run(){



    setScreen(800, 600, title);

    window.create(sf::VideoMode(getScreenW(),getScreenH()), title);
    std::cout<< "Window created succesfully\n";
    //level.loadLevelImage();
    script.printFileText();
    std::cout<< "Script loaded\n";
    //level.buildMap();
    loadTextures();
    loadFont();
    myMap.buildMatrix();

    window.setFramerateLimit(60);




    sNode *nodes = nullptr;
    int nMapHeight = 16;
    int nMapWidth = 16;

    nodes = new sNode[nMapWidth * nMapHeight];
    for(int x = 0; x < nMapWidth; x++){
        for(int y = 0; y < nMapHeight; y++){

        }
    }

    gameView.rotate(5);
    gameView.reset(sf::FloatRect(0.f,0.f,200.f,200.f));
    window.setView(gameView);


        while (window.isOpen())
    {





        sf::Event event;



        while (window.pollEvent(event))
        {
            handleEvents();


        }

        window.clear(sf::Color (50,200,50));
        ////////////////////////////
        //Stuff will be drawn here//
        ////////////////////////////
        //menuText[0].setPosition(20,20);


        stateMachine();


        moveCamera();


        //////////////////////////
        window.display();
    }
}

void Game::setScreen(int _w, int _h, sf::String _title){

    screenWidth = _w;
    screenHeight = _h;
    title = _title;
}


void Game::menu(){


}

void Game::setButtonsText(){



}


void Game::loadTextures(){
    //texmgr.loadTexture("background", "media/background.png");
    texmgr.loadTexture("grass_tile_1", "img/assets/environment/grass_tile_1.jpg");
    texmgr.loadTexture("water_tile_1", "img/assets/environment/water_tile_1.jpg");
    texmgr.loadTexture("testingGrass", "img/assets/environment/testingGrass.jpg");
    texmgr.loadTexture("test_bg", "img/assets/background/test_bg.jpg");

}

void Game::loadFont(){

    if (!font.loadFromFile("font/arial.ttf"))
    {
        std::cout<<"Font could not be loaded";
    }

}

void Game::loadMenuText(sf::Font &f, std::string textString, int x, int y, int size, sf::Text *tex){

    tex->setFont(f);
    tex->setCharacterSize(size);
    tex->setFillColor(sf::Color(0x225522ff));
    tex->setStyle(sf::Text::Bold);
    tex->setString(textString);
    tex->setPosition(x,y);

}


void Game::stateMachine(){

    sf::Sprite ground;
        int xx = 0;
        int yy = 0;

    GameStates state;
    state = STATE_GAME;
            sf::Text ButtonTex;


    switch(state){

        /////////////////////////////////////////////////////
        //////                Menu States               /////
        /////////////////////////////////////////////////////

        case STATE_START:

        background.setTexture(texmgr.getRef("test_bg"));
        window.draw(background);

            loadMenuText(font,"Play",40,50,80,&ButtonTex);
            menuText.push_back(ButtonTex);
            window.draw(menuText[0]);

            loadMenuText(font,"Options",40,140,26,&ButtonTex);
            menuText.push_back(ButtonTex);
            window.draw(menuText[1]);

            loadMenuText(font,"Credits",40,180,26,&ButtonTex);
            menuText.push_back(ButtonTex);
            window.draw(menuText[2]);

            loadMenuText(font,"Exit",40,220,26,&ButtonTex);
            menuText.push_back(ButtonTex);
            window.draw(menuText[3]);
            break;


        /////////////////////////////////////////////////////
        //////////////////END OF MENU STATES/////////////////
        /////////////////////////////////////////////////////

        /////////////////////////////////////////////////////
        //////                Game States               /////
        /////////////////////////////////////////////////////
        case STATE_GAME:
        for(int y = 0; y < myMap.y-1; y++){
            yy = 0;
            for(int x = 0; x < myMap.x-1; x++){
                ground.setTexture(texmgr.getRef(myMap.getImage(x,y)));
                //std::cout<<myMap.getImage(x,y);
                tile.push_back(&ground);
                tile[x+y]->setPosition(xx * 32, yy * 32);
                yy+=1;
                window.draw(*tile[x+y]);
            }
            xx+=1;
        }


        break;

        /////////////////////////////////////////////////////
        //////////////////END OF GAME STATES/////////////////
        /////////////////////////////////////////////////////
        case STATE_LEVEL:
            break;
        default:
            break;
    }
}

void Game::handleEvents(){

    if (event.type == sf::Event::Closed){
                window.close();
            }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                window.close();
            }


}

void Game::moveCamera(){



    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                speedViewY   -= gameSpeed * dt;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                speedViewY += gameSpeed * dt;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
                speedViewX -= gameSpeed * dt;

    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                speedViewX += gameSpeed * dt;
    }



            updateCamera();

            dt = time.asSeconds();
            time = clock.restart();



}

void Game::updateCamera(){


            gameView.move(speedViewX,speedViewY);
            window.setView(gameView);

            speedViewY = 0;
            speedViewX = 0;


}

    bool Game::isAnyKeyPressed(){
        for (int k = -1; k < sf::Keyboard::KeyCount; ++k)
        {
            if (sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(k)))
                return true;
        }
        return false;
    }
