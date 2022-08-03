#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool isInteger(string number)
{
    int intNumber = stoi(number);
    float floatNumber = stof(number);
    if (floatNumber == intNumber)
        return true;
    return false;
}

bool isNumberBigger(float number, float numberToCompare)
{
    if (number >= numberToCompare)
        return true;
    return false;
}

float getAverage(float sum, float elements)
{
    return (sum / elements);
}

float getVectorElementsSum(vector<float> numbers)
{
    float sum = 0;
    for (int i = 0; i < numbers.size(); i++)
    {
        float number = numbers[i];
        sum += number;
    }
    return sum;
}

float getVectorMaxValue(vector<float> numbers)
{
    float maxNumber;
    for (int i = 0; i < numbers.size(); i++)
    {
        float number = numbers[i];
        if (isNumberBigger(number, maxNumber))
            maxNumber = number;
    }
    return maxNumber;
}

void sortVector(vector<int> &numbers, bool ascendant = true)
{
    bool shouldRepeat = false;
    for (int i = 0; i < numbers.size(); i++)
    {
        int number = numbers[i];
        int nextNumber = numbers[i + 1];
        if (ascendant ? (number > nextNumber) : (number < nextNumber))
        {
            numbers[i] = numbers[i + 1];
            numbers[i + 1] = number;
            shouldRepeat = true;
        }
    }
    if (shouldRepeat)
        sortVector(numbers, ascendant);
}

vector<float> createNumberVectorFromFile(string fileName)
{
    vector<float> array;
    ifstream fs;
    string res;
    fs.open("./data/" + fileName, ios::app);
    while (fs >> res)
    {
        array.push_back(stof(res));
    }
    return array;
}