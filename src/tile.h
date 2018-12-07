
#ifndef TILE_H
#define TILE_H

#include <iostream>
#include <string>

class Tile{

private:

	int index;
	std::string name;
	int height;
	int hexValue;
	int friction;
	int popica;

public:

	Tile();
	Tile(int, std::string, int, int, int);

	std::string getName(){return name;}
	int getHeight(){return height;}
	int getHexValue(){return hexValue;}
	int getFriction(){return friction;}

	
	

};




#endif //TULE_H
