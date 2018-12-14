#include "game.hpp"

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





    //mouse_position = sf::Mouse::getPosition( window );


    sNode *nodes = nullptr;
    int nMapHeight = 16;
    int nMapWidth = 16;



    gameView.reset(sf::FloatRect(50.f,50.f,viewSizeX,viewSizeY));
    window.setView(gameView);





        myMap.nameImages();




        while (window.isOpen()){



        sf::Event event;


        while (window.pollEvent(event))
        {

            //mouse_position = sf::Mouse::getPosition( window );
            handleEvents();

        if(sf::Event::MouseWheelMoved){
            if(event.mouseWheel.delta < 0 && viewSizeX < 1300){
                viewSizeX += 60;
                viewSizeY += 60;
                gameView.setSize(viewSizeX,viewSizeY);
                updateCamera();
            }

            else if(event.mouseWheel.delta > 0 && viewSizeX > 800){
                viewSizeX -= 60;
                viewSizeY -= 60;
                gameView.setSize(viewSizeX,viewSizeY);
                updateCamera();
            }

            //std::cout<<"zoomed by "<< 60 * event.mouseWheel.delta<<"\n";
        }


            //if( event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape ) window.close();


        }

        window.clear(sf::Color (50,200,50));
        ////////////////////////////
        //Stuff will be drawn here//


        ////////////////////////////
        //menuText[0].setPosition(20,20);
        window.draw(ground);


        if(event.mouseButton.button == sf::Mouse::Left)
        {
            sf::RectangleShape box;
            box.setPosition( (sf::Mouse::getPosition(window).x + viewX) * viewSizeX , sf::Mouse::getPosition(window).y + viewY );
            box.setSize( sf::Vector2f( 40 , 40 ) );
            box.setFillColor( sf::Color::Red );
            std::cout<<sf::Mouse::getPosition(window).x<<"\n";
            window.draw( box );
        }


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




    state = STATE_GAME;

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


        for(int i = 0; i < 3; i++){
            ground.setTexture(texmgr.getRef(myMap.getImageName(i)));
            tile.push_back(&ground);
        }


        for(int y = 0; y < myMap.y-1; y++){
            yy = 0;
            for(int x = 0; x < myMap.x-1; x++){
                tile[myMap.getImgId(y,x)]->setPosition(xx * 32, yy * 32);

                //debugLog += "y:" + std::to_string(y) + " || x:" + std::to_string(x) + "\n";

                if(!tile[myMap.getImgId(y,x)]){
                    std::cout<<"You fucked up mate!";
                }
                window.draw(*tile[myMap.getImgId(y,x)]);
                //std::cout<<myMap.getImgId(y,x)<<"\n";
            }
            xx+=1;
        }

        //std::cout<<debugLog;

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

    // if (event.type == sf::Event::Closed){
    //             window.close();
    //         }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                window.close();
            }





}

void Game::moveCamera(){



    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
                speedViewY   -= gameSpeed * dt + (viewSizeX / 600);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
                speedViewY += gameSpeed * dt + (viewSizeX / 600);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
                speedViewX -= gameSpeed * dt + (viewSizeX / 600);

    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
                speedViewX += gameSpeed * dt + (viewSizeX / 600);
    }



            updateCamera();

            dt = time.asSeconds();
            time = clock.restart();



}

void Game::updateCamera(){


            gameView.move(speedViewX,speedViewY);
            window.setView(gameView);

            viewX += speedViewX;
            viewY += speedViewY;

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
