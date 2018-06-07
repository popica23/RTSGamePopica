#ifndef MENU_H
#define MENU_H

#include<iostream>
#include<string>
#include<vector>

class Menu{

private:

	std::string menuName;
	std::vector<std::string> options;

	int menuIndex;

	std::string userName;




public:

	void menuInit(std::string, int);

	void addOption(std::string);
	void addOptions(std::string,std::string);
	void addOptions(std::string,std::string,std::string);
	void addOptions(std::string,std::string,std::string,std::string);

	void addUserTextBox();

	void setUserName(std::string);
	std::string getUserName(){return userName;};


};

#endif // MENU_H
