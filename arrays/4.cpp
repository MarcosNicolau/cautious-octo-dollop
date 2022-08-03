#include <iostream>
#include <vector>
#include "utils.h"

using namespace std;

float getVectorMaxElement(vector<float> numbers)
{
    float maxElement;
    for (int i = 0; i < numbers.size(); i++)
    {
        float number = numbers[i];
        if (isNumberBigger(number, maxElement))
            maxElement = number;
    }
    return maxElement;
}

int main()
{
    vector<float> numbers = createNumberVectorFromFile("3.txt");
    float max = getVectorMaxElement(numbers);
    cout << "The max is " << max << endl;
    return 0;
}