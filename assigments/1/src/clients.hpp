#ifndef CLIENTS_H
#define CLIENTS_h

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "products.hpp"
#include "deliveries.hpp"

using namespace std;

struct Client
{
    int clientCode = 0;
    string name = "";
    vector<Delivery> deliveries;
};

// Reads the deliveries from the Names.txt file and returns an array loaded with them.
vector<string> getClientsName()
{
    vector<string> clients;
    fstream fs;
    fs.open("./data/Nombres.txt");
    if (!fs)
    {
        cout << "Err while loading clients..." << endl;
        return {};
    }
    string res;
    while (getline(fs, res))
    {
        clients.push_back(res);
    };
    return clients;
};

// Takes all the deliveries of each client and unifies them by product.
vector<Client> unifyClientDeliversByProduct(vector<Client> clients)
{
    vector<Client> updatedClients;
    for (int i = 0; i < clients.size(); i++)
    {
        Client client = clients[i];
        vector<Delivery> deliveries = unifyDeliveriesByProduct(client.deliveries);
        updatedClients.push_back({client.clientCode, client.name, deliveries});
    };
    return updatedClients;
};

// Gets all the deliveries and separates them by client.
vector<Client> filterDeliversByClients(vector<Delivery> deliveries, vector<string> clients_names)
{
    vector<Client> clientDeliveries = {};

    for (int i = 0; i < deliveries.size(); i++)
    {
        Delivery delivery = deliveries[i];
        // Used for checking if the client was pushed to the clientDeliveries vector
        bool clientFound = false;
        for (int l = 0; l < clientDeliveries.size(); l++)
        {
            // If true, it means that the client was pushed, so we just push the delivery
            if (clientDeliveries[l].clientCode == delivery.clientCode)
            {
                clientDeliveries[l].deliveries.push_back(delivery);
                clientFound = true;
            };
        };
        // If not, then it means that this is the first delivery from this client, so we push it
        if (!clientFound)
        {
            vector<Delivery> clientDelivers = {};
            clientDelivers.push_back(delivery);
            clientDeliveries.push_back({delivery.clientCode, clients_names[delivery.clientCode], clientDelivers});
        };
    };
    return clientDeliveries;
};

// Removes those deliveries that don't fulfill the minWeight condition
vector<Client> filterClientDeliveriesByWeight(vector<Client> clients, float minWeight)
{
    vector<Client> updatedClients;

    for (int i = 0; i < clients.size(); i++)
    {
        Client client = clients[i];
        Client updatedClient = {client.clientCode, client.name, {}};
        for (int l = 0; l < client.deliveries.size(); l++)
        {
            Delivery delivery = client.deliveries[l];
            if (delivery.weight >= minWeight)
            {
                updatedClient.deliveries.push_back(delivery);
            };
        };
        // If the size is 0, then the client does not have any delivery that fulfills the condition
        // So we just don't push it
        if (updatedClient.deliveries.size() > 0)
            updatedClients.push_back(updatedClient);
    };

    return updatedClients;
};

/**
 * !Important thing to note, for this fn to work, the clients must have its deliveries unified by products
 *
 * @returns the client with the highest amount of deliveries
 */
Client getClientWithHighestAmountOfDeliveries(vector<Client> clients)
{
    Client clientWithHighestAmountOfProducts;
    for (int i = 0; i < clients.size(); i++)
    {
        if (clients[i].deliveries.size() > clientWithHighestAmountOfProducts.deliveries.size())
            clientWithHighestAmountOfProducts = clients[i];
    };
    return clientWithHighestAmountOfProducts;
};

#endif