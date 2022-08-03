#include <iostream>
#include <fstream>

using namespace std;

bool isInteger(string number)
{
    int intNumber = stoi(number);
    float floatNumber = stof(number);
    if (floatNumber == intNumber)
        return true;
    return false;
}

int main()
{
    ifstream fs;
    string res;
    int sum{0};
    int average{0};
    int data_read_count{0};
    fs.open("input.txt", ios::app);
    if (!fs.is_open())
        return 1;
    while (fs >> res)
    {
        bool isInt = isInteger(res);
        if (isInt)
        {
            sum += stoi(res);
            ++data_read_count;
        }
        cout << "El number: " + res << (isInt ? " " : " no ")
             << "es un entero" << endl;
    }
    fs.close();
    average = sum / data_read_count;
    cout << "La suma de numero enteros es " << sum << endl;
    cout << "El promedio de números enteros es " << average << endl;
    return 0;
}