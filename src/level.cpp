#include "level.h"


	void Level::loadLevelImage(){

        std::string test;

        sf::Image image;
        image.loadFromFile("img/levels/testLevel.jpg");

	}

	int Level::readPixel(int x, int y, int levelIndex){

		pixelColor = levelImage[levelIndex].getPixel(x,y);

		if((pixelColor.r == 0)&&(pixelColor.g == 50)&&(pixelColor.b == 0)){
			tileIndex = 0;
		}

		return tileIndex;
	}
