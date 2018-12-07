#include "map.h"


void Map::buildMatrix(){

	image.loadFromFile("img/levels/testLevelt.png");
	x = image.getSize().x;
	y = image.getSize().y;
	for(int yy = 0; yy < image.getSize().y; yy++){
		std::vector<std::string> imgNameListRow;
		//- You'll thank me later
		for(int xx = 0; xx < image.getSize().x; xx++){
			std::cout << "Iteration [" << xx << "," << yy << "]\n";
			sf::Color tmp_col = image.getPixel(xx,yy);

			std::cout<<(int)tmp_col.r<<" ";
			std::cout<<(int)tmp_col.g<<" ";
			std::cout<<(int)tmp_col.b<<" ";
			std::cout<<"\n";

			if(is_same_color(tmp_col,0,255,0)){
				imgNameListRow.push_back("grass_tile_1");
				std::cout<<"grass 1\n";	
			}
			if(is_same_color(tmp_col,255,0,0)){
				imgNameListRow.push_back("testingGrass");
				std::cout<<"testGrassn\n";
			}
			if(is_same_color(tmp_col,0,0,255)){
				imgNameListRow.push_back("water_tile_1");
				std::cout<<"water 1\n";
			}
		}
		std::cout<<"\n";


		imgNameList.push_back(imgNameListRow);
	}


	for(int yy = 0; yy < image.getSize().y-1; yy++){
		//- You'll thank me later
		for(int xx = 0; xx < image.getSize().x-1; xx++){
			std::cout<<imgNameList[xx][yy]<<"\n";
		}
	}
}

bool Map::is_same_color(sf::Color color, uint8_t r, uint8_t g, uint8_t b)
{
    if(color.r == r && color.g == g && color.b == b)
        return true;
    return false;
}
