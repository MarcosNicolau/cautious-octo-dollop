#include <iostream>
#include <fstream>
#include "../../utils/index.hpp"
#include "./lists.hpp"

using namespace std;

// Declarations
struct Order
{
    int id;
    string client;
    string product;
    int quantity;
};

struct RemoveCriteriaParam
{
    string client;
    string product;
};

// Constants
const int order_client_size = 8;
const int order_product_size = 10;

// Utils
void print(Node<Order> *a)
{
    Order order = a->data;
    cout << order.id << " - " << order.client << " - " << order.product << " - " << order.quantity
         << endl;
};

void printLists(OrderedList<Order> o_id_list, OrderedList<Order> o_product_client_list)
{
    printDelimiter();
    cout << "List orderer by id:" << endl
         << endl;
    o_id_list.print(print);
    printDelimiter();
    cout << "List orderer by client and product:" << endl
         << endl;
    o_product_client_list.print(print);
};

// Binary files data reading
fstream &operator>>(fstream &fs, Order &order)
{
    fs.read(reinterpret_cast<char *>(&order.id), sizeof(order.id));
    order.client = readstring(fs, order_client_size);
    order.product = readstring(fs, order_product_size);
    fs.read(reinterpret_cast<char *>(&order.quantity), sizeof(order.quantity));
    return fs;
}

int readData(OrderedList<Order> &o_id_list, OrderedList<Order> &o_product_client_list)
{
    fstream fs;

    fs.open("./data/G06E02.bin", ios::binary | ios::in);
    if (!fs)
    {
        cout << "Could not open file" << endl;
        return 1;
    }
    Order res;
    while (fs >> res)
    {
        o_id_list.push(res);
        o_product_client_list.push(res);
    };
    return 0;
};

// Criteria for interacting with the linked lists
namespace Criteria
{
    bool sort_by_id(Order a, Order b)
    {
        return a.id < b.id ? true : false;
    };

    bool sort_by_product_client(Order a, Order b)
    {
        if (a.client == b.client)
            return a.product < b.product;
        return a.client < b.client;
    };

    bool search_by_id(Node<Order> *node, int id)
    {
        return node->data.id == id;
    };

    bool remove_by_client_product(Node<Order> *order, RemoveCriteriaParam criteria)
    {
        if (order->data.client == criteria.client && order->data.product == criteria.product)
        {
            // This means that the order will get deleted, and we want to print it when that happens
            print(order);
            return true;
        };
        return false;
    };

}

// Queries
namespace Queries
{
    void id(OrderedList<Order> list)
    {
        bool is_terminated = false;
        printDelimiter();
        while (!is_terminated)
        {
            int id;
            printDelimiter();
            cout << "Enter an id: ";
            cin >> id;
            if (id < 0)
            {
                is_terminated = true;
                printDelimiter();
                cout << "searching by id terminated" << endl;
                continue;
            }
            Node<Order> *order = list.search<int>(id, Criteria::search_by_id);
            if (order == nullptr)
            {
                cout << "an order with the given id does not exist, please try again" << endl;
                continue;
            }
            print(order);
        };
    };

    void remove(OrderedList<Order> o_id_list, OrderedList<Order> o_product_client_list)
    {
        bool is_terminated = false;
        while (!is_terminated)
        {
            printDelimiter();
            RemoveCriteriaParam criteria;
            cout << "Enter a client: ";
            cin >> criteria.client;
            if (criteria.client == "EOF")
                break;
            cout << endl;
            cout << "Enter a product: ";
            cin >> criteria.product;
            cout << endl;
            if (criteria.product == "EOF")
                break;

            cout << "The following orders were removed:" << endl
                 << endl;
            o_id_list.remove_all<RemoveCriteriaParam>(criteria, Criteria::remove_by_client_product);
            o_product_client_list.remove_all<RemoveCriteriaParam>(criteria, Criteria::remove_by_client_product);
        };
    };
}

int main()
{
    OrderedList<Order> o_id_list(Criteria::sort_by_id);
    OrderedList<Order> o_product_client_list(Criteria::sort_by_product_client);

    // Reading data and printing
    int res = readData(o_id_list, o_product_client_list);
    if (res == 1)
        return 1;
    printLists(o_id_list, o_product_client_list);

    // Queries
    Queries::id(o_id_list);
    Queries::remove(o_id_list, o_product_client_list);

    // Print
    printLists(o_id_list, o_product_client_list);

    // Empty the lists to free up memory
    o_id_list.empty();
    o_product_client_list.empty();

    return 0;
};