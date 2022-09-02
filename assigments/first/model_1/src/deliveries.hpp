#ifndef DELIVERIES_H
#define DELIVERIES_H

#include <iostream>
#include <vector>
#include <fstream>
#include "products.hpp"
#include "utils.hpp"

using namespace std;

struct Delivery
{
    int clientCode = 0;
    ProductType productCode;
    float weight = 0;
    float distance = 0;
};

// Reads the deliveries from the Datos.txt file and returns an array loaded with them.
vector<Delivery> getDeliveries(vector<string> clients)
{
    vector<Delivery> deliveries;
    fstream fs;
    fs.open("../data/Datos.txt");
    if (!fs)
    {
        cout << "Err while loading deliveries..." << endl;
        return {};
    }
    string res;
    while (getline(fs, res))
    {
        vector<string> data = splitString(res, '\t');
        Delivery delivery = {
            stoi(data[0]),
            ProductType(stoi(data[1])),
            stof(data[2]),
            stof(data[3]),
        };
        deliveries.push_back(delivery);
    };
    return deliveries;
};

// Gets a vector of deliveries and unifies the fields by adding them
vector<Delivery> unifyDeliveriesByProduct(vector<Delivery> deliveries)
{
    vector<Delivery> productsDelivery;
    for (int i = 0; i < deliveries.size(); i++)
    {
        Delivery delivery = deliveries[i];
        // Used for checking if the delivery already the product
        bool wasPushed = false;
        for (int l = 0; l < productsDelivery.size(); l++)
        {
            // If true, then it means that a delivery with that product was pushed, so we just add the fields together
            if (delivery.productCode == productsDelivery[l].productCode)
            {
                productsDelivery[l].clientCode = delivery.clientCode;
                productsDelivery[l].distance += delivery.distance;
                productsDelivery[l].weight += delivery.weight;
                wasPushed = true;
            };
        };
        // If not it means that there is no delivery with that product, so we push it
        if (!wasPushed)
        {
            productsDelivery.push_back({delivery.clientCode, delivery.productCode, delivery.weight, delivery.distance});
        };
    };
    return productsDelivery;
};

// Returns the amount of the passed product in the deliveries
int getDeliveriesCountForProduct(vector<Delivery> deliveries, ProductType product)
{
    int totalDeliveries = 0;
    for (int i = 0; i < deliveries.size(); i++)
    {
        if (deliveries[i].productCode == product)
            totalDeliveries++;
    };
    return totalDeliveries;
};

ProductType getProductWithHighestDistance(vector<Delivery> deliveries)
{
    float highestDistance = 0;
    ProductType product;
    for (int i = 0; i < deliveries.size(); i++)
    {
        Delivery delivery = deliveries[i];
        if (delivery.distance > highestDistance)
        {
            highestDistance = delivery.distance;
            product = delivery.productCode;
        };
    };
    return product;
};

/**
 * Sorts the deliveries by the distance
 * Note that it takes the array as a reference
 */
void sortDeliveriesByDistance(vector<Delivery> &deliveries, bool ascendant = true)
{
    bool shouldRepeat = false;
    for (int i = 0; i < deliveries.size(); i++)
    {
        Delivery delivery = deliveries[i];
        Delivery nextDelivery = deliveries[i + 1];
        if (ascendant ? (delivery.distance > nextDelivery.distance) : (delivery.distance < nextDelivery.distance))
        {
            deliveries[i] = deliveries[i + 1];
            deliveries[i + 1] = delivery;
            shouldRepeat = true;
        }
    }
    if (shouldRepeat)
        sortDeliveriesByDistance(deliveries, ascendant);
}

#endif