#ifndef SCRIPTREADER_H
#define SCRIPTREADER_H
#define checkIfEntered if(i==0)std::cout<<"It entered here " << i+1 << " time\n";else{std::cout<<"It entered here " << i+1 << " times\n";}

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <streambuf>
#include <sstream>

class scriptReader{

private:


    std::string fileName;
    std::string fileText;

    bool enteredObject = false;

    // File text
    std::string unitFileText = " ";
    std::string buildingFileText;
    std::string heroFileText = " ";
    std::string inputFileText = " ";
    std::string textAreaFileText = " ";
    std::string radioFileText = " ";
    std::string selectFileText = " ";
    std::string buttonFileText = " ";


    // Object text
    std::vector<std::string> unitObjectText;
    std::vector<std::string> buildingObjectText;
    std::vector<std::string> heroObjectText;
    std::vector<std::string> inputObjectText;
    std::vector<std::string> textAreaObjectText;
    std::vector<std::string> radioObjectText;
    std::vector<std::string> selectObjectText;

    std::string entityTypeLabel;

    std::string value;
    std::string typeValue;

    std::string fileHeader = "[filetype] = ";


    // List of types
    std::string unitType = "unit";
    std::string buttonType = "button";
    std::string inputType = "input";
    std::string radioType = "radio";
    std::string selectType = "select";
    std::string buildingType = "building";
    std::string heroType = "hero";


    // Items size
    int unitSize = 0;
    int buttonSize = 0;
    int inputSize = 0;
    int textAreaSize = 0;
    int radioSize = 0;
    int selectSize = 0;
    int buildingSize = 0;
    int heroSize = 0;

    // Select/Radio Options
    std::vector<int> radioOptionIndex;
    std::vector<int> selectOptionIndex;

    // Items label
    std::vector<std::string> unitName;
    std::vector<std::string> buildingName;
    std::vector<std::string> heroName;
    std::vector<std::string> buttonName;
    std::vector<std::string> radioName;
    std::vector<std::string> selectName;

    // Input watermark
    std::string inputWatermark;
    std::string textAreaWatermark;

    // entity stats stats
    std::vector <std::vector <std::string>> unitActions;
    std::vector <int> unitHP;
    std::vector <std::vector <std::string>> buildingActions;
    std::vector <int> buildingHP;
    std::vector <std::vector <std::string>> heroActions;
    std::vector <int> heroHP;

    std::vector<bool> unitCaster;
    std::vector<int> unitMP;
    std::vector<int> heroMP;

    std::vector <int> unitDamage;
    std::vector <int> heroDamage;

    std::vector <int> unitArmor;
    std::vector <int> buildingArmor;
    std::vector <int> heroArmor;

    std::vector <std::string> unitArmorType;
    std::vector <std::string> buildingArmorType;
    std::vector <std::string> heroArmorType;

    int unitSpeed;
    int heroSpeed;

    // Option getters
    std::vector<std::string> radioOption;
    std::vector<std::string> selectOption;



public:

    // check fileType
    int checkType();

    //////////////////////////////////////////////////////////////
    //////////////         Getter list              //////////////
    //////////////////////////////////////////////////////////////

    // index getters
    int getUnitSize(){return unitSize;}
    int getBuildingSize(){return buildingSize;}
    int getHeroSize(){return heroSize;}
    int getButtonSize(){return buttonSize;}
    int getInputSize(){return inputSize;}
    int getRadioSize(){return radioSize;}

    // health&mana getters
    int getUnitHealth(int index){return unitHP[index];}
    int getUnitMana(int index){return unitMP[index];}
    int getBuildingHealth(int index){return buildingHP[index];}
    int getHeroHealth(int index){return heroHP[index];}
    int getHeroMana(int index){return heroMP[index];}

    // armor getters
    int getUnitArmor(int index){return unitArmor[index];}
    std::string getUnitArmorType(int index){return unitArmorType[index];}
    int getBuildingArmor(int index){return buildingArmor[index];}
    std::string getBuildingArmorType(int index){return buildingArmorType[index];}
    int getHeroArmor(int index){return heroArmor[index];}
    std::string getHeroArmorType(int index){return heroArmorType[index];}

    // damage getters
    int getUnitDamage(int index){return unitDamage[index];}
    int getHeroDamage(int index){return heroDamage[index];}

    // actions getters
    std::string getUnitActions(int index, int rowIndex){return unitActions[index][rowIndex];}
    std::string getHeroActions(int index, int rowIndex){return heroActions[index][rowIndex];}
    std::string getBuildingActions(int index, int rowIndex){return buildingActions[index][rowIndex];}

    // text getters
    std::string getBuildingObjectText(int index){return buildingObjectText[index];}
    //std::string getBuildingFileText(){return buildingFileText;}


    //////////////////////////////////////////////////////////////
    //////////////        End Getter list           //////////////
    //////////////////////////////////////////////////////////////


    // type enum
    enum fileType {unit = 0, button = 1, input = 2, textArea = 3, radio = 4, select = 5, building = 6, hero = 7};
    enum raceType {human = 0, monster = 1, mermaid = 2};

    fileType fileT;
    raceType raceT;

    void buildScriptObjects();

    std::string readFileName();

    std::string unitFileContent();
    std::string buttonFileContent();
    std::string inputFileContent();
    std::string textAreaFileContent();
    std::string buildingFileContent();
    std::string heroFileContent();
    std::string radioFileContent();
    std::string selectFileContent();


    std::string trim(std::string);

    std::string eraseQuotationMark(std::string myString){return myString.substr(1,myString.length()-2);}


    //////////////////////////////////////////////////////////////
    //////////////           File parser            //////////////
    //////////////////////////////////////////////////////////////

    void createUnit();
    void createBuilding();
    void createHero();
    void createButton();
    void createInput();
    void createTextArea();
    void createRadio();
    void createSelect();

    void writeUnitObjectText();
    void writeBuildingObjectText();
    void writeHeroObjectText();
    void writeInputObjectText();
    void writeTextAreaObjectText();
    void writeRadioObjetText();
    void writeSelectObjectText();
    void wrtieButtonObectText();

    /////////////////////////
    /////   DEBUGGING   /////
    /////////////////////////

    void printFileText();

};


#endif // SCRIPTREADER_H
