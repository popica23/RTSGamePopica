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
	std::vector<int> imgId;
	const int imgCount = 3;

	std::vector<std::string> imgName;




public:


	void buildMatrix();


	std::string getImageGrid(int x,int y){return imgNameList[x][y];}
	bool is_same_color(sf::Color, uint8_t, uint8_t, uint8_t);
	int x;
	int y;
	int getImgCount(){return imgCount;}
	int getImgId(int x, int y){
		int id = x*image.getSize().y + y;
		//std::cout<<id;
		return imgId[id];
	}

	void nameImages();
	std::string getImageName(int x){return imgName[x];}


};


#endif // MAP_H


