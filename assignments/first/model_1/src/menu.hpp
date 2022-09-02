#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "deliveries.hpp"
#include "constants.hpp"
#include "clients.hpp"
#include "./console/index.hpp"

using namespace std;

namespace Buttons
{
    string item1 = "a";
    string item2 = "b";
    string item3 = "c";
};

// Receives the clients and a custom text
// And prints each client delivery products
void printClientsProducts(vector<Client> clients, string text)
{
    MenuComponents::renderSeparator();
    for (int i = 0; i < clients.size(); i++)
    {
        Client client = clients[i];
        MenuComponents::renderHeader("The client " + client.name);
        MenuComponents::renderParagraph(text);
        for (int l = 0; l < client.deliveries.size(); l++)
        {
            Delivery delivery = client.deliveries[l];
            MenuComponents::renderParagraph("  - " + productsMap[delivery.productCode]);
        };

        MenuComponents::blankLine();
        MenuComponents::renderSeparator();
    };
};

// Receives a client and shows each delivery product and the distance traveled
void printClientProductsDistance(Client client, string text)
{
    MenuComponents::renderHeader("The client " + client.name);
    MenuComponents::renderParagraph(text);
    MenuComponents::blankLine();
    MenuComponents::renderSeparator();
    sortDeliveriesByDistance(client.deliveries);
    for (int i = 0; i < client.deliveries.size(); i++)
    {
        Delivery delivery = client.deliveries[i];
        MenuComponents::renderParagraph("Product: " + productsMap[delivery.productCode]);
        MenuComponents::renderParagraph("Distance: " + to_string(delivery.distance));
        MenuComponents::blankLine();
        MenuComponents::renderSeparator();
    };
};

// Prints the number of deliveries for a given product
void printTotalDeliveriesForProduct(vector<Delivery> deliveries, ProductType product)
{
    int totalDeliveries = getDeliveriesCountForProduct(deliveries, product);
    MenuComponents ::renderSeparator();
    MenuComponents::renderParagraph("There were: " + to_string(totalDeliveries) + " deliveries for the " + productsMap[product] + " products");
    MenuComponents ::blankLine();
    MenuComponents ::renderSeparator();
};

void renderMenu(vector<Client> clients, vector<Delivery> deliveries)
{
    vector<Client> weightFilteredClients = filterClientDeliveriesByWeight(clients, Constants::minWeight);
    Client weightFilteredClientsWithHighestAmountOfProducts = getClientWithHighestAmountOfDeliveries(weightFilteredClients);
    MenuComponents::renderHeader("Hi there! this is the Deliveries.com software");
    MenuComponents::promptForEnter();
    while (true)
    {
        Console::clear();
        MenuComponents::renderParagraph("What do you want to check?");
        MenuComponents::renderButtonInstruction(Buttons::item1, "to see the clients that exceed 13000kg in products deliveries");
        MenuComponents::renderButtonInstruction(Buttons::item2, "to see the delivery distance of each product that exceeds 13000kg from the client that has the highest amount of products the mentioned capacity");
        MenuComponents::renderButtonInstruction(Buttons::item3, "to see the the total number of deliveries from the product that has the largest distance from the item B");
        string res = Console::getInput();
        if (res == Buttons::item1)
        {
            Console::clear();
            printClientsProducts(weightFilteredClients, "has exceed the " + to_string(Constants::minWeight) + "kg weight in the following products:");
        };
        if (res == Buttons::item2)
        {
            Console::clear();
            printClientProductsDistance(weightFilteredClientsWithHighestAmountOfProducts, "has the highest number of products that exceed " + to_string(Constants::minWeight) + "kg\nThe products and the distance traveled are:");
        }
        if (res == Buttons::item3)
        {
            Console::clear();
            printTotalDeliveriesForProduct(deliveries, getProductWithHighestDistance(weightFilteredClientsWithHighestAmountOfProducts.deliveries));
        }
        // Must add this to make the enter prompt below work
        cin.ignore();
        MenuComponents::promptForEnter();
    };
};

#endif
