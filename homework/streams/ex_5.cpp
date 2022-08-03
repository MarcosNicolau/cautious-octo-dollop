#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void typePrompt()
{
    cin.get() == '\n';
}

int main()
{

    fstream fs;
    fstream formattedFs;
    string res;
    string userInput;
    string fileName;

    cout << "Enter file name" << endl;
    cin >> fileName;
    fs.open(fileName + ".txt", fstream::in | fstream::out | fstream::ate);
    formattedFs.open(fileName + "_formatted" + ".txt", fstream::out);
    cout << "Type something (press ctrl+d to stop editing)" << endl;
    while (cin >> userInput)
    {
        if (cin.get() == '\n')
        {

            fs << userInput << endl
               << endl
               << flush;
            continue;
        }

        fs << userInput + " " << flush;
    }
    fs.seekg(0, fstream::beg);
    // split string and check with that until whe get to the 5 character.
    while (getline(fs, res))
    {
        if (res.size() < 5)
        {
            formattedFs << res << endl;
            continue;
        }
        // string words;
        // fs.seekg(5);
        // fs >> words;
        // cout << words;
        // formattedFs << words << endl;
        // fs.seekg(0);
    }
    fs.close();
    return 0;
}