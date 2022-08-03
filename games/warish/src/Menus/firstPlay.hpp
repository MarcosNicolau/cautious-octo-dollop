#include <iostream>
#include "vector"
#include "./components.hpp"
#include "../Classes/Console.hpp"
#include "../Classes/Characters/utils.hpp"
#include "../Classes/SavingManager.hpp"
#include "../utils/sleep.hpp"

using namespace std;

void showFamily(Family::Family family)
{
    string header = "You are playing with the " + Family::familyNamesMap[family.info.name] + "'s";
    MenuComponents::renderHeader(header, {true});
    for (int i = 0; i < family.members.size(); i++)
    {
        Character member = family.members[i];
        Info info = member.info;
        MenuComponents::blankLine();
        MenuComponents::renderSeparator();
        MenuComponents::blankLine();
        MenuComponents::renderHeader(info.name);
        MenuComponents::renderParagraph("Role: " + rolesDescription[info.role]);
        MenuComponents::renderParagraph("Age: " + to_string(info.age));
        MenuComponents::renderParagraph("Sex: " + sexDescription[info.sex]);
        MenuComponents::renderParagraph("Job: " + jobsDescription[info.job]);
        MenuComponents::renderParagraph("Hobby: " + hobbiesDescription[info.hobby]);
        MenuComponents::blankLine();
    };
    MenuComponents::promptForEnter();
};

void renderFirstPlayMenu()
{
    Console::clear();
    string welcomeMessage = "Hello there, and welcome to warish, a RPG terminal based game.";
    string welcomeMessage2 = "Since this is a new play, a new random family will be created.";
    MenuComponents::renderHeader(welcomeMessage, {true});
    MenuComponents::renderParagraph(welcomeMessage2);
    MenuComponents::promptForEnter();
    MenuComponents::renderParagraph("Creating random family...");
    Family::Family family = createFamily();
    sleep(2);
    showFamily(family);
    SavingManager::saveFirstPlay({true, family});
};