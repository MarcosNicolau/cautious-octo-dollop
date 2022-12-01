#include <iostream>
#include <fstream>

using namespace std;

const int total_products = 5;
const int total_clients = 8;
const float weight_limit = 13000;
const string data_path = "../data";

string clients_name[total_clients];
string products_name[total_products];

struct client
{
    float weight = 0;
    float distance = 0;
};

// This struct holds the client with the most products that exceeds the weight limit
struct exceedingClient
{
    int code = 0;
    int products_amount = 0;
    struct distances
    {
        float values[total_products];
        int pos[total_products];
    } distance;
};

void loadClientsData(client clients[total_clients][total_products], int deliveries[total_products])
{
    fstream fs;
    fs.open(data_path + "/Datos.txt");
    if (!fs)
    {
        cout << "ERROR WHILE READING DATA" << endl;
    };
    int client_code;
    int product_code;
    float weight;
    float distance;
    while (fs >> client_code >> product_code >> weight >> distance)
    {
        clients[client_code][product_code].weight += weight;
        clients[client_code][product_code].distance += distance;
        deliveries[product_code]++;
    };
};

void loadClientsNameAndProductsName(string clients_name[total_clients], string products_name[total_products])
{
    fstream fs;
    fs.open(data_path + "/Nombres.txt");
    if (!fs)
    {
        cout << "ERROR WHILE LOADING DATA" << endl;
    };
    int line{0};
    int clientIndex{0};
    int productIndex{0};
    string res;
    while (fs >> res)
    {
        if (line <= 7)
        {
            clients_name[clientIndex] = res;
            clientIndex++;
        }
        else
        {
            products_name[productIndex] = res;
            productIndex++;
        };
        line++;
    };
};

void printDelimiter()
{
    cout << endl;
    cout << "==================================================================" << endl;
    cout << endl;
};

template <class T>
void sortDobleArray(T array[], int array_2[], int dimension, bool ascendant = true)
{
    bool hasSwapped = false;

    for (int i = 0; i < dimension - 1; i++)
    {
        T number = array[i];
        T nextNumber = array[i + 1];
        if (ascendant ? (number > nextNumber) : number < nextNumber)
        {
            array[i] = nextNumber;
            array_2[i] = i + 1;
            array[i + 1] = number;
            array_2[i + 1] = i;
            hasSwapped = true;
        };
    };

    if (hasSwapped)
        sortDobleArray(array, array_2, dimension, ascendant);
};

/**
 * This does the logic to print the exercise 1 and receives a reference to the exceeding_client and calculates it.
 */
void calculateExercise1(client clients[total_clients][total_products], exceedingClient &client)
{
    printDelimiter();
    cout << "The following list shows the products of the clients that have exceed 13000kg" << endl
         << endl;

    for (int i = 0; i < total_clients; i++)
    {
        int exceedingProducts{0};
        cout << clients_name[i] << ":"
             << "\t";
        for (int j = 0; j < total_products; j++)
        {
            float weight{clients[i][j].weight};
            if (weight > weight_limit)
            {
                cout << products_name[j] << "\t";
                exceedingProducts++;
            };
        };
        if (exceedingProducts > client.products_amount)
        {
            client.code = i;
            client.products_amount = exceedingProducts;
        };
        cout << endl;
    };
};

void printExercise2(float distances[total_products], int pos[total_products], int client_code)
{
    printDelimiter();
    cout << "The following list shows the distance of the products that exceed " << weight_limit << "kg from the client " << clients_name[client_code] << endl;
    for (int i = 0; i < total_products; i++)
    {
        float distance = distances[i];
        int product_pos = pos[i];
        cout << products_name[product_pos] << ": " << distance << "km" << endl;
    };
};

void printExercise3(int product, int deliveries)
{
    printDelimiter();
    cout << "The amount of deliveries for the product " << products_name[product] << " is: " << deliveries << endl;
    printDelimiter();
};

void getExceedingClientProductsDistance(client clients[total_clients][total_products], exceedingClient &client)
{
    // Get the distance of the exceeding_client
    for (int i = 0; i < total_products; i++)
    {
        client.distance.values[i] = clients[client.code][i].distance;
        client.distance.pos[i] = i;
    };
};

int main()
{
    client clients[total_clients][total_products];
    int deliveries[total_products]{};
    exceedingClient exceeding_client;

    // Load data
    loadClientsData(clients, deliveries);
    loadClientsNameAndProductsName(clients_name, products_name);

    // EXERCISES

    // EX 1
    calculateExercise1(clients, exceeding_client);

    // Sort exceeding client distance
    getExceedingClientProductsDistance(clients, exceeding_client);
    sortDobleArray<float>(exceeding_client.distance.values, exceeding_client.distance.pos, total_products);

    // EX 2
    printExercise2(exceeding_client.distance.values, exceeding_client.distance.pos, exceeding_client.code);

    // EX 3
    int pos = exceeding_client.distance.pos[total_products - 1];
    printExercise3(pos, deliveries[pos]);
};
