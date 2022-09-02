#include <iostream>
#include "menu.hpp"
using namespace std;

int main()
{
    vector<string> clientsName = getClientsName();
    vector<Delivery> deliveries = getDeliveries(clientsName);
    vector<Client> clients = unifyClientDeliversByProduct(filterDeliversByClients(deliveries, clientsName));
    renderMenu(clients, deliveries);
    return 0;
};