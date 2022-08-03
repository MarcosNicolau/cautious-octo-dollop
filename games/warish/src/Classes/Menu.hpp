#include "./SavingManager.hpp"
#include "../Menus/index.hpp"

/**
 * This class is the manager of the menu.
 *
 * It renders the menus and reads the user input to render another menu
 *
 */
class MenuManager
{
public:
    MenuManager(){};
    static void showFirstPlayMenu()
    {
        renderFirstPlayMenu();
        MenuComponents::promptForEnter();
    };
    void showMainMenu()
    {
        renderMenu();
        string res = Console::getInput();
    };
    void showInventoryMenu(){};
    void showItemInfoMenu(){};
    void showPlayerStatsMenu(){};
    void showTravelMenu(){};
};