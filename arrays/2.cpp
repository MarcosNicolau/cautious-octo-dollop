#include <iostream>
#include <vector>
#include "utils.h"

using namespace std;

float getBiggerNumbersAverage(vector<float> numbers, float numberToCompare)
{
    float counter = 0;
    float sum = 0;
    for (int i = 0; i < numbers.size(); i++)
    {
        float number = numbers[i];
        if (isNumberBigger(number, numberToCompare))
        {
            sum += number;
            counter++;
        };
    }
    return getAverage(sum, counter);
}

float promptForNumberToCompare()
{
    float numberToCompare;
    cout << "Enter number to compare: " << endl;
    cin >> numberToCompare;
    return numberToCompare;
}

int main()
{
    float numberToCompare = promptForNumberToCompare();
    vector<float> myArray = createNumberVectorFromFile("2.txt");
    float average = getBiggerNumbersAverage(myArray, numberToCompare);
    cout << average << endl;
    return 0;
}