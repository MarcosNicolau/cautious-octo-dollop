#ifndef DATA_MAP_H
#define DATA_MAP_H

#include <iostream>
#include <array>

using namespace std;
enum ProductType
{
    FOOD,
    ELECTRIC,
    METALLIC,
    TEXTILE,
    CHEMICAL,
    // This field must be at the bottom and is for counting the number of product types
    COUNT
};

//! Important thing to note here, the names have to match the same position of ProductsTypes
array<string, 5> productsMap = {"Alimenticios", "Electrónicos", "Metálicos", "Textiles", "Químicos"};

#endif
