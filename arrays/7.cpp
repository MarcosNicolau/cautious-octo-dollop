#include <iostream>
#include <vector>
#include <array>
#include "utils.h"

using namespace std;

array<int, 2> getMaxValuesFromVector(vector<int> numbers)
{
    array<int, 2> maxNumbers = {0, 0};
    for (int i = 0; i < numbers.size(); i++)
    {
        int number = numbers[i];
        for (int l = 0; l < maxNumbers.size(); l++)
        {
            int maxNumberPos = maxNumbers[l];
            if (isNumberBigger(number, numbers[maxNumberPos]))
            {
                for (int e = l + 1; e < maxNumbers.size(); e++)
                {
                    maxNumbers[e] = maxNumbers[e - 1];
                }
                maxNumbers[l] = i;
                break;
            }
        }
    }
    return maxNumbers;
}

int main()
{
    vector<int> numbers = {6, 1, 3, 7, 9, 4, 10, 2, 8, 5};
    array<int, 2> maxNumbersPos = getMaxValuesFromVector(numbers);
    cout << "The max number pos are " << maxNumbersPos[0] << " and " << maxNumbersPos[1] << " and the numbers are " << numbers[maxNumbersPos[0]] << " and " << numbers[maxNumbersPos[1]] << endl;
    return 0;
}