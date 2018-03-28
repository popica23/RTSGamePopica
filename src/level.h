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

	std::vector <sf::Image> levelImage;
	sf::Color pixelColor;

public:

	void loadLevelImage();

	int readPixel(int,int,int);



};
#endif // LEVEL_H
