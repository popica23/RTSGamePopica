#include "menu.h"

void Menu::menuInit(std::string menuName, int menuIndex){

	this->menuName = menuName;
	this->menuIndex = menuIndex;

}

void Menu::addOption(std::string option){

	options.push_back(option);

}

void Menu::addOptions(std::string option1,std::string option2){

	options.push_back(option1);
	options.push_back(option2);

}

void Menu::addOptions(std::string option1,std::string option2,std::string option3){

	options.push_back(option1);
	options.push_back(option2);
	options.push_back(option3);

}

void Menu::addOptions(std::string option1,std::string option2,std::string option3,std::string option4){

	options.push_back(option1);
	options.push_back(option2);
	options.push_back(option3);
	options.push_back(option4);

}

void setUserName(std::string name){
	//userName = name;
}
