#include <iostream>
#include <vector>
#include "utils.h"

using namespace std;

vector<int> promptUserToPushVectorElements(vector<int> &array, string promptMessage, void (*func)(vector<int> &, int) = 0)
{
    int res;
    cout << promptMessage << endl;
    while (cin >> res)
    {
        if (func)
            func(array, res);
        else
            array.push_back(res);
    }
    return array;
}

void pushVectorElementCondition(vector<int> &numbers, int res)
{
    if (!numbers.size())
    {
        numbers.push_back(res);
        return;
    }
    int lastNumber = numbers[numbers.size() - 1];
    if (res > lastNumber)
    {
        numbers.push_back(res);
    }
    else
        cout << "Number not added, they must be in ascending order" << endl;
    return;
}

void getMaxSuccessiveVectorDiff(vector<int> numbers)
{
    int maxDiff = 0;
    // This are the elements used in the diff
    int element1 = 0;
    int element2 = 0;
    for (int i = 0; i < numbers.size(); i++)
    {
        int prev = !i ? 0 : numbers[i - 1];
        int current = numbers[i];
        int difference = current - prev;
        if (difference > maxDiff)
        {
            maxDiff = difference;
            element1 = i - 1;
            element2 = i;
        }
    }
    cout << "The max difference is " << maxDiff << endl;
    cout << "The elements are " << element1 << " and " << element2 << endl;
}

int main()
{
    vector<int> numbers;
    promptUserToPushVectorElements(numbers, "Enter integers in ascending order:", &pushVectorElementCondition);
    getMaxSuccessiveVectorDiff(numbers);
    return 0;
}