#ifndef CONSOLE_H
#define CONSOLE_H
#include <iostream>
#include <string>

using namespace std;

enum ConsoleFontColors
{
    NONE = 0,
    DEFAULT = 39,
    BLACK = 30,
    RED = 31,
    GREEN = 32,
    YELLOW = 33,
    BLUE = 34,
    PURPLE = 35,
    CYAN = 36,
    GRAY = 37,
};

enum ConsoleBackgroundColors
{
    BG_NONE = 0,
    BG_DEFAULT = 49,
    BG_BLACK = 40,
    BG_RED = 41,
    BG_LIGHT_RED = 101,
    BG_GREEN = 42,
    BG_LIGHT_GREEN = 102,
    BG_YELLOW = 103,
    BG_BLUE = 44,
    BG_LIGHT_BLUE = 104,
    BG_PURPLE = 45,
    BG_LIGHT_PURPLE = 105,
    BG_CYAN = 46,
    BG_TEAL = 106,
    BG_GRAY = 47,
    BG_DARK_GRAY = 100,
    BG_WHITE = 107,
};

void resetConsoleTextAppearance()
{
    string defaultLook = "\033[0m";
    printf(defaultLook.c_str());
}

struct ConsoleAppearance
{
    ConsoleFontColors color = DEFAULT;
    ConsoleBackgroundColors background = BG_DEFAULT;
    bool bold = false;
    bool italic = false;
    bool highlight = false;
    bool flashing = false;
    bool underlined = false;
};

string buildLinuxAppearance(ConsoleAppearance opts)
{
    string color = ";" + to_string(opts.color);
    string background = ";" + to_string(opts.background);
    string bold = (opts.bold ? ";1" : "");
    string italic = (opts.italic ? ";3" : "");
    string highlight = (opts.highlight ? ";7" : "");
    string flashing = (opts.flashing ? ";5" : "");
    string underlined = (opts.underlined ? ";4" : "");
    return "\033[" + color + background + bold + highlight + italic + underlined + flashing + "m";
}

class Console
{

public:
    static void clear()
    {
#if defined _WIN32
        system("cls");
#elif defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
        system("clear");
#elif defined(__APPLE__)
        system("clear");
#endif
    }
    static void print(string text, ConsoleAppearance appearance = {})
    {
        clear();
        printf((buildLinuxAppearance(appearance) + text).c_str());
        resetConsoleTextAppearance();
        cout << endl;
    }
    static void printWithNoClear(string text, ConsoleAppearance appearance = {})
    {
        printf((buildLinuxAppearance(appearance) + text).c_str());
        resetConsoleTextAppearance();
        cout << endl;
    };
    static void printWithNoEndl(string text, ConsoleAppearance appearance = {})
    {
        printf((buildLinuxAppearance(appearance) + text).c_str());
        resetConsoleTextAppearance();
    };
    static void showGeneralInputErr()
    {
        printWithNoClear("Bad input, try again");
    };
    static string getInput()
    {
        string command = "";
        printf((buildLinuxAppearance({DEFAULT, BG_DEFAULT, true})).c_str());
        cin >> command;
        resetConsoleTextAppearance();
        return command;
    };
};

#endif