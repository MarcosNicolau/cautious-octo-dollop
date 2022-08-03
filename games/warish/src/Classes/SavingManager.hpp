#ifndef SAVING_MANAGER_H
#define SAVING_MANAGER_H

#include <string>
#include <iostream>
#include "../Structs/savings.hpp"
#include "../utils/stream.hpp"
#include "../utils/sleep.hpp"
#include "../utils/conversions.hpp"
#include "../constants.hpp"

using namespace std;

using namespace Constants::Data;

class SavingManager
{

public:
    static bool isGameData()
    {
        return getDataFromFile(buildFilePath(Base::fileName), Base::init) != "";
    };
    static void saveFirstPlay(BaseSave data)
    {
        saveDataToFile(buildFilePath(Base::fileName), Base::init, to_string(data.hasInit));
        saveFamily(data.family);
    };
    static Character getPlayerData(){
        // string name = getDataFromFile(buildFilePath(PlayerD::fileName), PlayerD::name);
        // int gold = stoi(getDataFromFile(buildFilePath(PlayerD::fileName), PlayerD::gold, "0"));
        // int exp = stoi(getDataFromFile(buildFilePath(PlayerD::fileName), PlayerD::exp, "0"));
        // int level = stoi(getDataFromFile(buildFilePath(PlayerD::fileName), PlayerD::level, "0"));

        // Player player(name, {}, {level, exp, gold});
        // return player;
    };
    static bool savePlayerData()
    {
        return true;
    };
    static void saveGameData()
    {
        printf("GAME SAVED");
    };
};

#endif