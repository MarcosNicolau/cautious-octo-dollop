#ifndef ITEMS_H
#define ITEMS_H
#include <iostream>
#include <vector>

using namespace std;

enum ItemType
{
    WEAPON,
    POTION,
    SPELL,
    COLLECTABLE
};

struct Item
{
    int id = 0;
    string name;
    ItemType type;
};

enum WeaponType
{
    ATTACK,
    DEFEND,
};

struct Weapon : Item
{
    int damage = 0;
    int defense = 0;
    WeaponType type;
    string description = "";
};

enum PotionType
{
    HEAL,
    MANA,
};

struct Potion : Item
{
    PotionType type;
    int value = 1;
};

struct Spell : Item
{
};

struct Collectable : Item
{
    int value = 0;
};

vector<Weapon> weapons = {
    {0, "Sword", WEAPON, 0, 0, ATTACK, "A basic sword"},
    {0, "Shield", WEAPON, 0, 0, DEFEND, "A basic shield"},
};

#endif