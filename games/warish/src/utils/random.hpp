#ifndef RANDOM_H
#define RANDOM_H
#include <iostream>
#include <random>

using namespace std;

bool isValueInNumbersToIgnore(int value, vector<int> numbersToIgnore)
{
    bool isValue = false;
    for (int i = 0; i < numbersToIgnore.size(); i++)
    {
        if (numbersToIgnore[i] == value)
        {
            isValue = true;
            break;
        };
    };
    return isValue;
};

/*Returns a random integer between the given range*/
int getRandomInteger(int min, int max, vector<int> numbersToIgnore = {})
{
    int value = 0;
    do
    {
        struct timespec clock;
        value = min + (rand() % (max - min + 1));

    } while (isValueInNumbersToIgnore(value, numbersToIgnore));
    return value;
}

string getRandomId()
{

    return to_string(rand() % (9999999999999999999999999 - 0 + 1));
};

#endif