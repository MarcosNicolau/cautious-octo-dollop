#include <iostream>
#include "./components.hpp"
#include "../Classes/Console.hpp"

using namespace std;

namespace MainMenuBtns
{
    const string INVENTORY = "I";
    const string QUESTS = "J";
    const string EQUIPMENT = "E";
    const string UPGRADES = "U";
    const string TRAVEL = "M";
    const string STATS = "P";
};

using namespace MainMenuBtns;

void showTutorial()
{
    string tutorial = "";
    MenuComponents::renderParagraph(tutorial, {true});
    bool confirm = MenuComponents::promptConfirmation("");
}

void showActionsMenu()
{
    MenuComponents::renderHeader("What are you doing next?");
    MenuComponents::renderSeparator();
    MenuComponents::renderAction("Open inventory", INVENTORY);
    MenuComponents::renderAction("Open equipment", EQUIPMENT);
    MenuComponents::renderAction("Open stats", STATS);
    MenuComponents::renderAction("Open upgrades", UPGRADES);
    MenuComponents::renderAction("Open quests", QUESTS);
    MenuComponents::renderAction("Travel", TRAVEL);
    MenuComponents::renderSeparator();
};

void renderMenu()
{
    Console::clear();
    showActionsMenu();
}