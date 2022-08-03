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

    while (getline(cin, userInput))
    {
        if (userInput.size() < 4)
        {
            fs << userInput << endl;
            continue;
        }
        string overFlowText = userInput.substr(4);
        fs << userInput.substr(0, 4) << endl;
        while (overFlowText.length() > 4)
        {
            fs << overFlowText.substr(0, 4) << endl;
            overFlowText = overFlowText.substr(4);
            continue;
        }
    }
    fs.close();
    return 0;
}