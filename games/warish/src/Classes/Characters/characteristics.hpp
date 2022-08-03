#ifndef CHARACTERISTICS_H
#define CHARACTERISTICS_H
#include <iostream>
#include <vector>
#include <array>

using namespace std;

namespace Characteristics
{

    //! DO NOT CHANGE ORDER
    enum Role
    {
        FATHER,
        MOTHER,
        SON,
        DAUGHTER,
        OLD_FRIEND,
        ACQUAINTANCE,
        AUNT,
        UNCLE,
        COUSIN,
    };

    enum Hobbies
    {
        GUITAR = 0,
        COOKING = 1,
        RUNNING = 2,
        COUNT_0
    };

    enum History
    {
        LAWYER_0 = 0,
        ORPHAN_0 = 1,
        SOCCER_PLAYER_0 = 2,
        STUDENT_0 = 3,
        COUNT_1
    };

    enum Jobs
    {
        ACCOUNTANT,
        LAWYER,
        UNEMPLOYED,
        COLLEGE,
        HIGH_SCHOOL,
        MILITAR,
        NEVER_WORKED,
        RETIRED,
        COUNT_2
    };

    enum Sex
    {
        MALE = 0,
        FEMALE = 1,
    };

    namespace PhysicalAppearance
    {

        enum BodyType
        {

            NORMAL,
            SKINNY,
            MUSCULAR,
            FAT,
            COUNT_3,
        };

        enum Hair
        {
            BALD,
            SHORT,
            MEDIUM,
            LONG,
            COUNT_4,
        };

        enum Face
        {
            LUNARS,
            PIMPLES,
            ACNE,
            UGLY,
            SYMMETRICAL,
            UNSYMMETRICAL,
            COUNT_5,
        };

        enum Skin
        {
            BLACK,
            WHITE,
            COUNT_6,
        };

        struct Appearance
        {
            int bodyType;
            int hair;
            int face;
            int skin;
        };
    };

    /**
     * This works as a map for the enums
     * For it to work, the value of the enum value has to match the array position
     */
    vector<string> hobbiesDescription = {
        "Playing the guitar",
        "Cooking",
        "Running",
    };

    vector<string> historyDescription = {
        "You were a successful lawyer",
        "You were an orphan",
        "You were a soccer player",
        "You were a student at Harvard",
    };

    vector<string> jobsDescription = {
        "Accountant",
        "Lawyer",
        "Unemployed",
        "College",
        "High school",
        "Militar",
        "Never worked",
        "Retired",
    };

    vector<string> rolesDescription = {
        "Father",
        "Mother",
        "Son",
        "Daughter",
        "Old friend",
        "Acquaintance",
        "Aunt",
        "Uncle",
        "Cousin",
    };

    vector<string> sexDescription = {
        "Male",
        "Female",
    };

    struct Names
    {
        vector<string> male = {"John", "Michael", "Dwight", "Jimmy"};
        vector<string> female = {"Laura", "Pamela", "Maria", "Olivia"};
    } names;
};

#endif