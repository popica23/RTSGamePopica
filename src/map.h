#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <vector>
#include <string>
#include "tile.h"



#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window.hpp>

class Map{
private:

	sf::Image image;
	std::vector <std::vector <std::string>> imgNameList;



public:

	void buildMatrix();


	std::string getImage(int x,int y){return imgNameList[x][y];}
	bool is_same_color(sf::Color, uint8_t, uint8_t, uint8_t);
	int x;
	int y;

};


#endif // MAP_H
