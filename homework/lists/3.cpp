#include <iostream>
#include "./lists.hpp"
#include <fstream>
#include "../../utils/index.hpp"

using namespace std;

const int debt_client_size = 8;

struct Debt
{
    string client;
    int month;
    int amount;
};

fstream &operator>>(fstream &fs, Debt &debt)
{
    debt.client = readstring(fs, debt_client_size);
    fs.read(reinterpret_cast<char *>(&debt.month), sizeof(debt.month));
    fs.read(reinterpret_cast<char *>(&debt.amount), sizeof(debt.amount));
    return fs;
};

int read_data(OrderedList<Debt> &list)
{
    fstream fs;
    fs.open("./data/G06E03.bin", ios::binary | ios::in);
    if (!fs)
    {
        cout << "Could not open file" << endl;
        return 1;
    }
    Debt debt;
    while (fs >> debt)
    {
        list.push(debt);
    };
    return 0;
};

bool push_criteria(Debt a, Debt b)
{
    if (a.client == b.client)
        return a.month < b.month;
    return a.client < b.client;
};

void print(Node<Debt> *a)
{
    Debt debt = a->data;
    cout << debt.client << " - " << debt.month << " - " << debt.amount
         << endl;
};

void consolidate(OrderedList<Debt> debts)
{
    Node<Debt> *list = debts.list;
    while (list != nullptr && list->next != nullptr)
    {
        bool hasMatched = false;
        if (list->data.month == list->next->data.month)
        {
            list->data.amount += list->next->data.amount;
            debts.remove_next(list);
            hasMatched = true;
        };
        if (hasMatched)
            continue;
        list = list->next;
    };
};

int main()
{
    OrderedList<Debt> debts(push_criteria);

    // Read data
    int res = read_data(debts);
    if (res == 1)
        return 1;
    printDelimiter();
    cout << "Debts without consolidating:" << endl
         << endl;
    debts.print(print);
    consolidate(debts);
    printDelimiter();
    cout << "Consolidated debts:" << endl
         << endl;
    debts.print(print);
    debts.print(print);

    return 0;
};