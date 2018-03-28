#include "game.h"

void Game::run(){


    setScreen(800, 600, "title");

    window.create(sf::VideoMode(getScreenW(),getScreenH()), title);

    level.loadLevelImage();
    script.printFileText();




        while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed){
                window.close();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                window.close();
            }
        }

        window.clear(sf::Color (50,200,50));
        //////////////////////////
        //Stuff will render here//
        //////////////////////////



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

