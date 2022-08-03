#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream fs;
    fstream formattedFs;
    string userInput;
    string fileName;

    cout
        << "Enter file name" << endl;
    cin >> fileName;
    fs.open(fileName + ".txt", fstream::in | fstream::out | fstream::trunc);
    cout << "Type something (press ctrl+d to stop editing)" << endl;
    string wordToWrite;
    while (cin)
    {
        cin >> userInput;
        if ((wordToWrite.length() + userInput.length()) < 80)
        {
            wordToWrite = wordToWrite + userInput;
        }
    }
    fs.close();
    return 0;
}