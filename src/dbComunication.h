#ifndef DBCOMUNICATION_H
#define DBCOMUNICATION_H

#include<iostream>
#include<string>
#include<vector>

#include "scriptReader.h"


class dbComunication{

private:

    scriptReader script;

    //mySql

    std::string type;
    std::string label;

    std::vector<std::string> categoryList;

    bool updateReady;
    bool localChangeStatus;

    bool localWasChanged;
    bool serverWasChanged;

    bool logInStatus;

    std::string username;
    std::string password;

    std::string packedLogInInfo();

public:

	void duplicateTempDB();
	void updateTempDB();



	void getUpdateStatusDB(bool);

	bool changeUpdateIsReady();

	bool checkIfCategoryExists(std::string);

	void btnUpdate(std::string buttonStatus);

	void fetchServerDatabase();

	bool checkChangesOnServer();

	void syncInfo();

	bool checkUser(std::string, std::string);

	bool getLocalWasChanged(){return localWasChanged;}


	void unpackUserInfo();
	std::string getUsername(){return username;}
	std::string getPassword(){return password;}




};



#endif // DBCOMUNICATION_H
