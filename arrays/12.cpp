#include <iostream>
#include <vector>
#include "utils.h"

using namespace std;

float getMatrixElementsAverage(double matrix[][3], int rows, int columns)
{
    double accumulator = 0;
    int elements = rows * columns;
    for (int i = 0; i < rows; i++)
    {
        for (int l = 0; l < columns; l++)
        {
            accumulator += matrix[i][l];
        }
    }
    return getAverage(accumulator, elements);
}

int main()
{
    int rows = 4;
    int columns = 3;
    double matrix[rows][3] = {{1, 2, 3}, {3, 5, 6}, {9, 4, 2}, {0, 3, 8}};
    float matrixAverage = getMatrixElementsAverage(matrix, rows, columns);
    cout << matrixAverage << endl;
    return 0;
}