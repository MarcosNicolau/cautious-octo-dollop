#ifndef MENU_BASE_COMPONENTS
#define MENU_BASE_COMPONENTS
#include <iostream>
#include "../Classes/Console.hpp"

using namespace std;

namespace styles
{
    ConsoleAppearance header = {DEFAULT, BG_DEFAULT, false, false, true};
    ConsoleAppearance paragraph = {DEFAULT, BG_DEFAULT, false, true, false};
    ConsoleAppearance input = {DEFAULT, BG_DEFAULT, true, false, false};
    ConsoleAppearance success = {DEFAULT, BG_GREEN, true, true, false};
    ConsoleAppearance failure = {DEFAULT, BG_RED, true, true, false};
    ConsoleAppearance warning = {ConsoleFontColors::BLACK, BG_YELLOW, true, true, false};
    ConsoleAppearance button = {DEFAULT, BG_DEFAULT, true, true, true};
    ConsoleAppearance italic = {DEFAULT, BG_DEFAULT, false, true, false};
};

enum MessageStatus
{
    SUCCESS,
    FAILURE,
    WARNING,
};

struct ComponentsOpts
{
    bool shouldClear = false;
    bool shouldEndl = true;
};

class MenuComponents
{

private:
    static void render(string text, ConsoleAppearance style, ComponentsOpts opts)
    {
        if (opts.shouldClear)
            Console::clear();
        Console::printWithNoEndl(text, style);
        if (opts.shouldEndl)
            cout << endl;
    };

public:
    static void renderButton(string text, ComponentsOpts opts = {false, false})
    {
        render("(" + text + ")", styles::button, opts);
    };
    static void renderHeader(string text, ComponentsOpts opts = {false, true})
    {
        render(text, styles::header, opts);
    };
    static void renderParagraph(string text, ComponentsOpts opts = {false, true})
    {
        render(text, styles::paragraph, opts);
    };
    static void renderStatusMessage(string text, enum MessageStatus status, ComponentsOpts opts = {false, true})
    {
        ConsoleAppearance style = status == SUCCESS ? styles::success : status == FAILURE ? styles::failure
                                                                                          : styles::warning;
        render(text, style, opts);
    };
    static void showGeneralInputErr()
    {
        Console::printWithNoEndl("Bad input, try again");
    };
    static void blankLine()
    {
        cout << endl;
    };
    static void renderAction(string text, string btn)
    {
        blankLine();
        renderParagraph(text + " ", {false, false});
        renderButton(btn, {false, true});
        renderParagraph("----------------------");
        blankLine();
    };
    static void renderSeparator()
    {

        MenuComponents::renderParagraph("==============================================================================================");
    };
    static void promptForEnter()
    {
        string text = "Press enter to continue";
        Console::printWithNoEndl(text, {DEFAULT, BG_DEFAULT, false, true});
        while (1)
        {
            if (cin.get() == '\n')
                break;
        }
    };
    static bool promptConfirmation(string text = "\nAre you sure?")
    {
        Console::printWithNoClear(text, {GREEN, BG_DEFAULT, true, false});
        Console::printWithNoEndl("Enter ", styles::italic);
        renderButton("y");
        Console::printWithNoEndl(" to confirm or ", styles::italic);
        renderButton("n");
        Console::printWithNoClear(" to cancel ", styles::italic);
        string res = Console::getInput();
        if (res == "y")
            return true;
        if (res == "n")
            return false;
        else
            promptConfirmation();
    };
};

#endif