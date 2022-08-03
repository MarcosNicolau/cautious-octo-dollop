#ifndef CHARACTER_INFO_H
#define CHARACTER_INFO_H
#include <iostream>
#include "characteristics.hpp"
#include "../../utils/random.hpp"

using namespace std;
using namespace Characteristics;

struct Info
{
    Sex sex;
    Role role;
    string name;
    Jobs job;
    History history;
    Hobbies hobby;
    PhysicalAppearance::Appearance appearance;
    int age;
};

Info getRandomInfo(Role role)
{
    using namespace PhysicalAppearance;
    Info info;
    info.role = role;
    // Randomize character
    if (role == FATHER || role == SON)
        info.sex = MALE;
    else
        info.sex = FEMALE;
    if (role == FATHER || role == MOTHER)
        info.age = getRandomInteger(30, 70);
    if (role == SON || role == DAUGHTER)
        info.age = getRandomInteger(16, 25);
    if (info.sex == MALE)
        info.name = names.male[getRandomInteger(0, names.male.size())];
    else
        info.name = names.female[getRandomInteger(0, names.female.size())];
    if (info.age >= 60)
        info.job = getRandomInteger(0, 1) ? RETIRED : NEVER_WORKED;
    if (info.age < 25 & info.age >= 18)
        info.job = getRandomInteger(0, 1) ? COLLEGE : NEVER_WORKED;
    if (info.age < 18)
        info.job = HIGH_SCHOOL;
    else
        info.job = Jobs(getRandomInteger(0, Jobs::COUNT_2 - 1, {RETIRED}));
    info.history = History(getRandomInteger(0, History::COUNT_1 - 1));
    info.hobby = Hobbies(getRandomInteger(0, Hobbies::COUNT_0 - 1));
    // Appearance
    info.appearance.bodyType = getRandomInteger(0, BodyType::COUNT_3 - 1);
    info.appearance.hair = getRandomInteger(0, Hair::COUNT_4 - 1);
    info.appearance.face = getRandomInteger(0, Face::COUNT_5 - 1);
    info.appearance.skin = getRandomInteger(0, Skin::COUNT_6 - 1);
    return info;
};

#endif