#include "./Menu.hpp"
#include "Console.hpp"
#include "SavingManager.hpp"
#include <stdio.h>
#include <signal.h>
#include <thread>
#include <random>
#include <time.h>

class GameManager
{

private:
    static void sigintHandler(int sig_num)
    {
        bool confirmation = MenuComponents::promptConfirmation();
        if (confirmation)
            exit(1);
    }
    void initializeGame()
    {
        MenuManager::showFirstPlayMenu();
        // loadGame();
    }
    void loadGame()
    {
        atexit(exitGame);
        // Load player data... (inventory, quests, locations, etc...)
        MenuManager menu;
        menu.showMainMenu();
    }

public:
    void startGame()
    {
        signal(SIGINT, sigintHandler);
        // Seed to get random numbers
        srand(time(0));
        bool isGameData = SavingManager::isGameData();
        if (isGameData)
            loadGame();
        else
            initializeGame();
    };
    static void exitGame()
    {
        SavingManager::saveGameData();
    };
};