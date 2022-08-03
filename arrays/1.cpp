#include <iostream>
#include <vector>

using namespace std;

int arrayCounter(vector<int> number_array)
{
    int counter{0};
    for (int i = 0; i < number_array.size(); i++)
    {
        counter += number_array[i];
    }
    return counter;
}

int main()
{
    vector<int> myArray{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int count = arrayCounter(myArray);
    cout << count << endl;
    return 0;
}