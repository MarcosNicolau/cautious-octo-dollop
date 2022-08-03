#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream inputFile;
    ofstream oddOutFile;
    ofstream evenOutFile;
    int res;
    inputFile.open("input.txt");
    oddOutFile.open("odd.txt", ios::trunc);
    evenOutFile.open("even.txt", ios::trunc);
    while (inputFile >> res)
    {
        if (res % 2 == 0)
        {
            oddOutFile << res << endl;
            continue;
        }
        evenOutFile << res << endl;
    }
    oddOutFile.close();
    evenOutFile.close();
    inputFile.close();

    return 0;
}