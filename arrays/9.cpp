#include <iostream>
#include <vector>
#include "utils.h"

using namespace std;

int main()
{
    vector<int> numbers = {0, 8, 32, 1, 4, 5, 6, 2, 4326, 6, 65, 34, 53412};
    sortVector(numbers);
    for (int i = 0; i < numbers.size(); i++)
    {
        cout << numbers[i] << endl;
    }
    return 0;
}