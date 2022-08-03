#ifndef FAMILY_H
#define FAMILY_H
#include <iostream>
#include <vector>

using namespace std;

namespace Family
{

    enum Name
    {
        WILLIAMS,
        THOMPSON,
        NICOLAU,
        ALVAREZ,
        MAJUL,
        COUNT_0
    };

    enum History
    {
        NO_FATHER_0,
        NO_MOTHER_0,
        NO_CHILDS_0,
        RICH_0,
        POOR_0,
        NORMAL_0,
        COUNT_1
    };

    vector<string> familyNamesMap = {
        "Williams",
        "Thompson",
        "Nicolau",
        "Alvarez",
        "Majul"};

    vector<string> historiesMap = {
        "No father",
        "No mother",
        "No childs",
        "Rich",
        "Poor",
        "Normal",
    };

    struct Info
    {
        Name name;
        History history;
    };

    struct Family
    {
        Info info;
        vector<Character> members;
    };

};

#endif
