#ifndef BASE_SKILLS_H
#define BASE_SKILLS_H
#include <iostream>
#include <vector>
#include <array>
#include "info.hpp"
#include "characteristics.hpp"
#include "../../utils/random.hpp"

using namespace std;
using namespace Characteristics;
using namespace PhysicalAppearance;

struct Skills
{
    float strength = 0;
    float stealth = 0;
    float speed = 0;
    float intelligence = 0;
};

bool isElementInVector(int element, vector<int> elements)
{
    bool isValue = false;
    for (int i = 0; i < elements.size(); i++)
    {
        if (elements[i] == element)
        {
            isValue = true;
            break;
        }
    };
    return isValue;
};

// This fn returns the modifiers for the strength, speed, stealth and intelligence based on the age
Skills getAgeModifiers(int age)
{
    if (age >= 16 && age < 18)
        return {-0.5, 1, 1, -0.5};
    if (age >= 18 && age < 26)
        return {0.5, 1, 1.5, 0};
    if (age >= 26 && age < 30)
        return {1, 0.5, 0.5, 0.5};
    if (age >= 30 && age < 40)
        return {1, 0, -0.5, 1};
    if (age >= 40 && age < 50)
        return {0.5, -0.5, -1, 1.5};
    if (age >= 50 && age < 60)
        return {0, -0.5, -1.5, 2};
    if (age >= 60 && age < 70)
        return {-0.5, -1, -2, 3};
};

float getRandomStrength(Info info)
{
    float minStrength = 1;
    float maxStrength = 3;
    vector<int> jobsThatIncreaseStrength = {Jobs::MILITAR};
    vector<int> hobbiesThatIncreaseStrength = {Hobbies::RUNNING};
    vector<int> historiesThatIncreaseStrength = {History::SOCCER_PLAYER_0};
    int ageModifier = getAgeModifiers(info.age).strength;
    if (info.appearance.bodyType == MUSCULAR)
    {
        minStrength += 2;
        maxStrength += 2;
    };
    if (info.appearance.bodyType == FAT)
    {
        minStrength += 1;
        maxStrength += 1;
    };
    if (info.appearance.bodyType == SKINNY)
    {
        minStrength -= 1;
        maxStrength -= 1;
    };
    if (info.appearance.skin == Skin::BLACK)
    {
        minStrength += 0.5;
        maxStrength += 0.5;
    };
    if (isElementInVector(info.job, jobsThatIncreaseStrength) ||
        isElementInVector(info.history, historiesThatIncreaseStrength) ||
        isElementInVector(info.hobby, hobbiesThatIncreaseStrength))
    {
        minStrength += 0.5;
        maxStrength += 0.5;
    };
    minStrength += ageModifier;
    maxStrength += ageModifier;

    return getRandomInteger(minStrength, maxStrength);
};

float getRandomStealth(Info info)
{
    float minStealth = 1;
    float maxStealth = 2;
    vector<int> jobsThatIncreaseStealth = {Jobs::MILITAR};
    vector<int> hobbiesThatIncreaseStealth = {Hobbies::RUNNING};
    vector<int> historiesThatIncreaseStealth = {History::ORPHAN_0};
    int ageModifier = getAgeModifiers(info.age).stealth;
    if (info.appearance.bodyType == FAT)
    {
        minStealth -= 0.5;
        maxStealth -= 0.5;
    };
    if (info.appearance.bodyType == SKINNY)
    {
        minStealth += 0.5;
        maxStealth += 0.5;
    };
    if (isElementInVector(info.job, jobsThatIncreaseStealth) ||
        isElementInVector(info.history, historiesThatIncreaseStealth) ||
        isElementInVector(info.hobby, hobbiesThatIncreaseStealth))
    {
        minStealth += 0.5;
        maxStealth += 0.5;
    };
    minStealth += ageModifier;
    maxStealth += ageModifier;

    return getRandomInteger(minStealth, maxStealth);
};

float getRandomSpeed(Info info)
{
    float minSpeed = 1;
    float maxSpeed = 2;
    vector<int> jobsThatIncreaseSpeed = {Jobs::MILITAR};
    vector<int> hobbiesThatIncreaseSpeed = {Hobbies::RUNNING};
    vector<int> historiesThatIncreaseSpeed = {History::SOCCER_PLAYER_0};
    int ageModifier = getAgeModifiers(info.age).stealth;
    if (info.appearance.bodyType == FAT)
    {
        minSpeed -= 1;
        maxSpeed -= 1;
    };
    if (info.appearance.bodyType == SKINNY)
    {
        minSpeed += 1;
        maxSpeed += 1;
    };
    if (info.appearance.bodyType == MUSCULAR)
    {
        minSpeed += 0.5;
        maxSpeed += 0.5;
    };
    if (isElementInVector(info.job, jobsThatIncreaseSpeed) ||
        isElementInVector(info.history, historiesThatIncreaseSpeed) ||
        isElementInVector(info.hobby, hobbiesThatIncreaseSpeed))
    {
        minSpeed += 0.5;
        maxSpeed += 0.5;
    };
    minSpeed += ageModifier;
    maxSpeed += ageModifier;

    return getRandomInteger(minSpeed, maxSpeed);
};

float getRandomIntelligence(Info info)
{
    float minIntelligence = 1;
    float maxIntelligence = 2;
    vector<int> jobsThatIncreaseIntelligence = {Jobs::ACCOUNTANT, Jobs::COLLEGE, Jobs::LAWYER};
    vector<int> hobbiesThatIncreaseIntelligence = {Hobbies::GUITAR, Hobbies::COOKING};
    vector<int> historiesThatIncreaseIntelligence = {History::LAWYER_0, History::ORPHAN_0, History::STUDENT_0};
    int ageModifier = getAgeModifiers(info.age).stealth;
    if (info.appearance.bodyType == MUSCULAR)
    {
        minIntelligence -= 0.5;
        maxIntelligence -= 0.5;
    };
    if (isElementInVector(info.job, jobsThatIncreaseIntelligence) ||
        isElementInVector(info.history, historiesThatIncreaseIntelligence) ||
        isElementInVector(info.hobby, hobbiesThatIncreaseIntelligence))
    {
        minIntelligence += 0.5;
        maxIntelligence += 0.5;
    };
    minIntelligence += ageModifier;
    maxIntelligence += ageModifier;

    return getRandomInteger(minIntelligence, maxIntelligence);
};

Skills getRandomBaseSkills(Info info)
{
    float strength = getRandomStrength(info);
    float stealth = getRandomStealth(info);
    float speed = getRandomSpeed(info);
    float intelligence = getRandomIntelligence(info);

    return {strength, stealth, speed, intelligence};
};
#endif