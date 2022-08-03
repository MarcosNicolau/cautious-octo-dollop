#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <iostream>

using namespace std;

namespace Constants
{
    namespace Data
    {
        namespace Base
        {
            const string fileName = "base.txt";
            const string init = "init";
            const string tutorial = "tutorial";
        };
        namespace FamilySave
        {
            const string directory = "family/";
            const string fileName(string name, string id)
            {
                return name + id + ".txt";
            };
            namespace General
            {
                const string fileName = "general.txt";
                const string name = "name";
                const string history = "history";
            };
            namespace Info
            {
                const string directory = "info/";
                const string id = "id";
                const string name = "name";
                const string sex = "sex";
                const string role = "role";
                const string hobby = "hobby";
                const string history = "history";
                const string job = "job";
                const string bodyType = "bodyType";
                const string hair = "hair";
                const string face = "face";
                const string skin = "skin";

            };
            namespace Skills
            {

                const string directory = "base_skills/";
                const string strength = "strength";
                const string stealth = "stealth";
                const string speed = "speed";
                const string intelligence = "intelligence";
            }
        };
    };
}
#endif