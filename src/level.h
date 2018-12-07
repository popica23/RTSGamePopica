#ifndef LEVEL_H
#define LEVEL_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/System.hpp>

#include <iostream>
#include <string>
#include <vector>



class Level{

private:
	std::vector<std::vector<int>> levelMap;
	std::vector <int>levelMapRow;
	int tileIndex;

	std::vector <std::string> levelList;

	sf::Image levelImage;
	sf::Color pixelColor;

public:

	void loadLevelImage();

	int readPixel(int,int);

	void buildMap();

	int mapTileValue(int x, int y){return levelMap[x][y];}


};
#endif // LEVEL_H

