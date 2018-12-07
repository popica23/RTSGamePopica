#include "scriptReader.h"


int scriptReader::checkType(){

    //if()

    switch(fileT){

    case unit:
        entityTypeLabel = unitType;

        break;
    case button:
        entityTypeLabel = buttonType;

        break;
    case input:
        entityTypeLabel = inputType;

        break;
    case radio:
        entityTypeLabel = radioType;

        break;
    case select:
        entityTypeLabel = selectType;

        break;

    default:
        std::cout<<"This request type does not exist\n\n\n\t\t####If error persists please try reinstalling game or send a ticket to developer####";
        break;


    }

    return fileT;

}


std::string scriptReader::buildingFileContent(){

    std::ifstream buildingFile;
    buildingFile.open ("scripts/buildings.txt");
    if(buildingFile){
    buildingFileText.assign((std::istreambuf_iterator<char>(buildingFile)),
                (std::istreambuf_iterator<char>()));
    }
    else{
        std::cout<<"\n\n\nFile does not exist\n\n\n";
    }
    buildingFile.close();

    return buildingFileText;
}

std::string scriptReader::unitFileContent(){

    std::ifstream unitFile;
    unitFile.open ("scripts/units.txt");
    if(unitFile){
    unitFileText.assign((std::istreambuf_iterator<char>(unitFile)),
                (std::istreambuf_iterator<char>()));
    }
    else{
        std::cout<<"\n\n\nFile does not exist\n\n\n";
    }

    unitFile.close();

    return unitFileText;
}

std::string scriptReader::heroFileContent(){

    std::ifstream heroFile;
    heroFile.open ("scripts/hero.txt");
    if(heroFile){
        heroFileText.assign((std::istreambuf_iterator<char>(heroFile)),
                (std::istreambuf_iterator<char>()));
    }
    else{
        std::cout<<"\n\n\nFile does not exist\n\n\n";
    }

    heroFile.close();

    return heroFileText;
}

std::string scriptReader::inputFileContent(){

    std::ifstream inputFile;
    inputFile.open ("scripts/input.txt");
    if(inputFile){
        inputFileText.assign((std::istreambuf_iterator<char>(inputFile)),
                             std::istreambuf_iterator<char>());
    }
    else{
        std::cout<<"\n\n\nFile does not exist\n\n\n";
    }

    inputFile.close();

    return inputFileText;
}

std::string scriptReader::textAreaFileContent(){

    std::ifstream textAreaFile;
    textAreaFile.open ("scripts/textArea.txt");
    if(textAreaFile){
        textAreaFileText.assign((std::istreambuf_iterator<char>(textAreaFile)),
                                std::istreambuf_iterator<char>());
    }
    else{
        std::cout<<"\n\n\nFile does not exist\n\n\n";
    }

    textAreaFile.close();

    return radioFileText;
}

std::string scriptReader::radioFileContent(){

    std::ifstream radioFile;
    radioFile.open ("scripts/textArea.txt");
    if(radioFile){
        radioFileText.assign((std::istreambuf_iterator<char>(radioFile)),
                             std::istreambuf_iterator<char>());
    }
    else{
        std::cout<<"\n\n\nFile does not exist\n\n\n";
    }

    radioFile.close();

    return selectFileText;
}

std::string scriptReader::selectFileContent(){

    std::ifstream selectFile;
    selectFile.open("scripts/select.txt");
    if(selectFile){
        selectFileText.assign((std::istreambuf_iterator<char>(selectFile)),
                                std::istreambuf_iterator<char>());
    }
    else{
        std::cout<<"\n\n\nFile does not exist\n\n\n";
    }

    return textAreaFileText;
}

std::string scriptReader::buttonFileContent(){

    std::ifstream selectFile;
    selectFile.open("scripts/button.txt");
    if(selectFile){
        selectFileText.assign((std::istreambuf_iterator<char>(selectFile)),
                                std::istreambuf_iterator<char>());
    }
    else{
        std::cout<<"\n\n\nFile does not exist\n\n\n";
    }

    return buttonFileText;
}

std::string scriptReader::trim(std::string myString){

    int i = 0;
    while(myString[i] == ' '){
        i++;
    }
    myString = myString.substr(i,myString.length());

    i = myString.length();

    while(myString[i] == ' '){
        i--;
    }

    myString = myString.substr(0,i);

    return myString;
}





void scriptReader::writeBuildingObjectText(){


    int pozStart;
    int objectCounter = 0;
    bool checkSetPozStart;
    //int substrLength;
    std::string tempObjectText;

    for(unsigned int i = 0; i < buildingFileText.length() - 2; i++){

        if(buildingFileText.substr(i,2) == "##"){

            if(enteredObject == false){
                enteredObject = true;
                checkSetPozStart = false;
                i+=2;
            }
            else{
                buildingObjectText.push_back(buildingFileText.substr(pozStart, objectCounter));
                enteredObject = false;
                checkSetPozStart = false;
                objectCounter = 0;
                buildingSize++;
            }
        }

        if((enteredObject == true)&&(checkSetPozStart == false)){
                pozStart = i;
                checkSetPozStart = true;
        }
        if(enteredObject == true){
            objectCounter ++;
        }
    }
}

void scriptReader::writeUnitObjectText(){

    int pozStart;
    int objectCounter = 0;
    bool checkSetPozStart;
    std::string tempObjectText;

    for(unsigned int i = 0; i < unitFileText.length() - 2; i++){

        if(unitFileText.substr(i,2) == "##"){

            if(enteredObject == false){
                enteredObject = true;
                checkSetPozStart = false;
                i+=2;
            }
            else{
                buildingObjectText.push_back(buildingFileText.substr(pozStart, objectCounter));
                enteredObject = false;
                checkSetPozStart = false;
                objectCounter = 0;
                buildingSize++;
            }
        }

        if((enteredObject == true)&&(checkSetPozStart == false)){
                pozStart = i;
                checkSetPozStart = true;
        }
        if(enteredObject == true){
            objectCounter ++;
        }
    }
}

void scriptReader::writeHeroObjectText(){

    int pozStart;
    int objectCounter = 0;
    bool checkSetPozStart;
    std::string tempObjectText;

    for(unsigned int i = 0; i < heroFileText.length() - 2; i++){

        if(heroFileText.substr(i,2) == "##"){

            if(enteredObject == false){
                enteredObject = true;
                checkSetPozStart = false;
                i+=2;
            }
            else{
                buildingObjectText.push_back(buildingFileText.substr(pozStart, objectCounter));
                enteredObject = false;
                checkSetPozStart = false;
                objectCounter = 0;
                buildingSize++;
            }
        }

        if((enteredObject == true)&&(checkSetPozStart == false)){
                pozStart = i;
                checkSetPozStart = true;
        }
        if(enteredObject == true){
            objectCounter ++;
        }
    }
}

void scriptReader::writeInputObjectText(){

    int pozStart;
    int objectCounter = 0;
    bool checkSetPozStart;
    std::string tempObjectText;

    for(unsigned int i = 0; i < inputFileText.length() - 2; i++){

        if(inputFileText.substr(i,2) == "##"){

            if(enteredObject == false){
                enteredObject = true;
                checkSetPozStart = false;
                i+=2;
            }
            else{
                buildingObjectText.push_back(buildingFileText.substr(pozStart, objectCounter));
                enteredObject = false;
                checkSetPozStart = false;
                objectCounter = 0;
                buildingSize++;
            }
        }

        if((enteredObject == true)&&(checkSetPozStart == false)){
                pozStart = i;
                checkSetPozStart = true;
        }
        if(enteredObject == true){
            objectCounter ++;
        }
    }
}

void scriptReader::writeTextAreaObjectText(){

    int pozStart;
    int objectCounter = 0;
    bool checkSetPozStart;
    std::string tempObjectText;

    for(unsigned int i = 0; i < textAreaFileText.length() - 2; i++){

        if(textAreaFileText.substr(i,2) == "##"){

            if(enteredObject == false){
                enteredObject = true;
                checkSetPozStart = false;
                i+=2;
            }
            else{
                buildingObjectText.push_back(buildingFileText.substr(pozStart, objectCounter));
                enteredObject = false;
                checkSetPozStart = false;
                objectCounter = 0;
                buildingSize++;
            }
        }

        if((enteredObject == true)&&(checkSetPozStart == false)){
                pozStart = i;
                checkSetPozStart = true;
        }
        if(enteredObject == true){
            objectCounter ++;
        }
    }
}

void scriptReader::writeRadioObjetText(){

    for(unsigned int i = 0; i < textAreaFileText.length() - 1; i++){

        if(textAreaFileText.substr(i,i+1) == "##"){
            if(enteredObject == false){
                enteredObject = true;
                i++;
            }
            else{
                enteredObject = false;
                textAreaSize ++;
                i++;
            }
        }



        if(enteredObject == true){
            textAreaObjectText[textAreaSize] += textAreaFileText[i];
        }
    }
}

void scriptReader::writeSelectObjectText(){

    for(unsigned int i = 0; i < selectFileText.length() - 1; i++){

        if(selectFileText.substr(i,i+1) == "##"){
            if(enteredObject == false){
                enteredObject = true;
                i++;
            }
            else{
                enteredObject = false;
                selectSize ++;
                i++;
            }
        }



        if(enteredObject == true){
            selectObjectText[selectSize] += selectFileText[i];
        }
    }
}

void scriptReader::printFileText(){
    buildingFileContent();
    writeBuildingObjectText();
    createBuilding();
}


void scriptReader::createUnit(){

        for(int i = 0; i < unitSize; ++i){

        std::stringstream unitObj_ss;
        std::string line;

        unitObjectText[i] = unitObjectText[i].substr(1,unitObjectText[i].length() - 1);
        unitObj_ss << unitObjectText[i];
        std::vector<std::string> unitActionsRow;
        bool addedToAtions = true;
            do{

                std::getline(unitObj_ss, line, '\n');

                if(line.find("[unit label] = ") != std::string::npos){


                    unitName.push_back(trim(line.substr(line.find("=") + 1, line.length() - line.find("="))));
                    unitName[i] = unitName[i].substr(1,unitName[i].length()-2);

                    //std::cout<<"Building Name: "<<buildingName[i]<<"\n\n";
                    }
                if(line.find(unitName[i] + " [\"index\"] = ")){

                }



            }while(line.length() > 0);
    }
}

void scriptReader::createBuilding(){


    for(int i = 0; i < buildingSize; ++i){

        std::stringstream buildObj_ss;
        std::string line;

        buildingObjectText[i] = buildingObjectText[i].substr(1,buildingObjectText[i].length() - 1);
        buildObj_ss << buildingObjectText[i];
        std::vector<std::string> buildingActionsRow;
        bool addedToAtions = true;
            do{

                std::getline(buildObj_ss, line, '\n');

                //std::cout<<"\nLine:\n"<<line<<"\n";

                    if(line.find("[building label] =") != std::string::npos){


                    buildingName.push_back(trim(line.substr(line.find("=") + 1, line.length() - line.find("="))));
                    buildingName[i] = buildingName[i].substr(1,buildingName[i].length()-2);

                    //std::cout<<"Building Name: "<<buildingName[i]<<"\n\n";
                    }

                    if(line.find(buildingName[i] + " [\"health\"] = ") != std::string::npos){
                        //std::cout<<"If it crashes after this I fucked up \n";
                        buildingHP.push_back(std::stoi(eraseQuotationMark(trim(line.substr(line.find("=") + 1, line.length() - line.find("="))))));

                        std::cout<<buildingName[i] + " health: "<<buildingHP[i]<<"\n";
                        //std::cout<<std::stoi(eraseQuotationMark(trim(line.substr(line.find("=") + 1, line.length() - line.find("=")))));
                    }
                    if(line.find(buildingName[i] + " [\"armor\"] = ") != std::string::npos){

                        buildingArmor.push_back(std::stoi(eraseQuotationMark(trim(line.substr(line.find("=") + 1, line.length() - line.find("="))))));
                        std::cout<<buildingName[i] + " armor: "<<buildingArmor[i]<<"\n";
                    }
                    if(line.find(buildingName[i] + " [\"armor type\"] = ") != std::string::npos){

                        buildingArmorType.push_back(eraseQuotationMark(trim(line.substr(line.find("=") + 1, line.length() - line.find("=")))));
                        std::cout<<buildingName[i] + " armor type: "<<buildingArmorType[i]<<"\n";
                    }
                    if(line.find(buildingName[i] + " [\"action\"] = ") != std::string::npos){

                        buildingActionsRow.push_back(eraseQuotationMark(trim(line.substr(line.find("=") + 1, line.length() - line.find("=")))));
                        addedToAtions = false;
                    }

                    std::cout<<"\n";
            }while(line.length() > 0);

            if(addedToAtions == false){
                buildingActions.push_back(buildingActionsRow);
                addedToAtions = true;
            }

    }



}

void scriptReader::createHero(){

}

void scriptReader::createButton(){

}
void scriptReader::createInput(){

}
void scriptReader::createTextArea(){

}

void scriptReader::createRadio(){

}
void scriptReader::createSelect(){

}
