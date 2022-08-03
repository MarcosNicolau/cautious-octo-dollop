#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string toUpperCase(string str)
{
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
}