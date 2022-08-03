#ifndef CHARACTERS_H
#define CHARACTERS_H
#include <iostream>
#include "../../utils/random.hpp"
#include "info.hpp"
#include "baseSkills.hpp"
#include "characteristics.hpp"

using namespace std;
using namespace Characteristics;

class Character
{

public:
    string id = getRandomId();
    Info info;
    Skills skills;
    Character(Role role)
    {
        info = getRandomInfo(role);
        skills = getRandomBaseSkills(info);
    };
    Character(string characterId, Info inf, Skills ski)
    {
        id = characterId;
        info = inf;
        skills = ski;
    };
};

#endif
