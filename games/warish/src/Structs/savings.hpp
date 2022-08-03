#include <iostream>
#include <vector>
#include "../constants.hpp"
#include "../Classes/Characters/Characters.hpp"
#include "../Classes/Characters/family.hpp"
#include "../utils/stream.hpp"

using namespace std;
using namespace Constants::Data;

struct BaseSave
{
    bool hasInit;
    Family::Family family;
};

string buildFilePath(string fileName)
{
    return "./data/" + fileName;
};

vector<BulkSave> getCharacterInfoSave(Character member)
{
    Info info = member.info;
    PhysicalAppearance::Appearance appearance = member.info.appearance;
    namespace I = FamilySave::Info;

    return {
        {I::id, member.id},
        {I::bodyType, to_string(appearance.bodyType)},
        {I::face, to_string(appearance.face)},
        {I::hair, to_string(appearance.hair)},
        {I::skin, to_string(appearance.skin)},
        {I::name, info.name},
        {I::sex, to_string(info.sex)},
        {I::hobby, to_string(info.hobby)},
        {I::history, to_string(info.history)},
        {I::role, to_string(info.role)},
    };
};

vector<BulkSave> getCharacterSkillsSave(Character member)
{
    Skills skills = member.skills;
    namespace S = FamilySave::Skills;

    return {
        {S::strength, to_string(skills.strength)},
        {S::stealth, to_string(skills.stealth)},
        {S::intelligence, to_string(skills.intelligence)},
        {S::speed, to_string(skills.speed)},
    };
};

void saveFamily(Family::Family family)
{
    namespace F = FamilySave;
    namespace G = FamilySave::General;
    namespace I = FamilySave::Info;
    namespace S = FamilySave::Skills;
    Family::Info info = family.info;

    bulkSave(buildFilePath(F::directory + G::fileName), {{G::name, to_string(info.name)}, {G::history, to_string(info.history)}});

    for (int i = 0; i < family.members.size(); i++)
    {
        Character member = family.members[i];
        string fileName = FamilySave::fileName(member.info.name, member.id);
        bulkSave(buildFilePath(F::directory + I::directory + fileName), getCharacterInfoSave(member));
        bulkSave(buildFilePath(F::directory + S::directory + fileName), getCharacterSkillsSave(member));
    };
};