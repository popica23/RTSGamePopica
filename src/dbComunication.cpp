#include "dbComunication.h"


	void dbComunication::syncInfo(){

		if(getLocalWasChanged() == true){
			// Send request to update serverdatabase
		}

	}


	void dbComunication::getUpdateStatusDB(bool dbUpdateStatus){

			updateReady = dbUpdateStatus;

		}

	bool dbComunication::changeUpdateIsReady(){

		if(updateReady == true){
			updateReady = false;
		}
		else{
			updateReady = true;
		}
	}

	bool dbComunication::checkIfCategoryExists(std::string categoryName){

		for(int i = 0; i < categoryList.size(); i++){
			if(categoryList[i] == categoryName){
				return true;
			}
		}

		return false;

	}

	bool dbComunication::checkUser(std::string u, std::string p){

		if((getUsername() == u) && (getPassword() == p)){
			return true;
		}

		return false;

	}

