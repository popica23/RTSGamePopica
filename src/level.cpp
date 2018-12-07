#include "level.h"


	void Level::loadLevelImage(){

        std::string test;

       	if(levelImage.loadFromFile("img/levels/testLevel.jpg")){
            std::cout<<"Image found";
       	}



	}

	int Level::readPixel(int x, int y){

		pixelColor = levelImage.getPixel(x,y);

		if((pixelColor.r == 0)&&(pixelColor.g == 50)&&(pixelColor.b == 0)){
			tileIndex = 0;
		}
		if((pixelColor.r == 0)&&(pixelColor.g == 0)&&(pixelColor.b == 50)){
			tileIndex = 1;
		}

		return tileIndex;
	}

	void Level::buildMap(){
		for(int x = 0; x < 100; x++){
            for(int y = 0; y < 100; y++){
                levelMap[x][y] = readPixel(x,y);
            }
		}
	}
