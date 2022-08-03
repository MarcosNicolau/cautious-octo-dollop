#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fs;
    float res;
    float lowestValue;
    bool isLowestValueInitialized{false};

    fs.open("input.txt");
    while (fs >> res)
    {
        if ((res < lowestValue) || !isLowestValueInitialized)
        {
            lowestValue = res;
            !isLowestValueInitialized && (isLowestValueInitialized = true);
            continue;
        }
    }
    fs.close();
    cout << "The lowest value is: " << lowestValue << endl;
    return 0;
}