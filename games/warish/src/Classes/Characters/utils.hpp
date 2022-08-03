#ifndef CHARACTERS_UTILS_H
#define CHARACTERS_UTILS_H
#include <iostream>
#include <vector>
#include "../../utils/random.hpp"
#include "Characters.hpp"
#include "family.hpp"

using namespace std;

Family::History getFamilyHistory(vector<Character> members)
{
    // TODO: Make an algorithm that based on the members we get a family history

    return Family::History(getRandomInteger(0, Family::History::COUNT_1 - 1));
};

Family::Family createFamily()
{
    vector<Character> family;
    bool isFather = !!getRandomInteger(0, 10);
    bool isMother = !!getRandomInteger(0, 10);
    if (isFather)
        family.push_back(Character(FATHER));
    if (isMother)
        family.push_back(Character(MOTHER));
    int numberOfChilds = getRandomInteger(0, 4);
    for (int i = 0; i < numberOfChilds; i++)
    {
        /**
         * * Notice that for this to work, the SON and DAUGHTER in the enum have to be followed
         */
        family.push_back(Character(Role(getRandomInteger(SON, DAUGHTER))));
    };
    Family::History history = getFamilyHistory(family);
    Family::Name name = Family::Name(getRandomInteger(0, Family::Name::COUNT_0 - 1));
    return {name, history, family};
};

#endif
