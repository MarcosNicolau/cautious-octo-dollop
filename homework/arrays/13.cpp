#include <iostream>
#include <vector>
#include "utils.h"

using namespace std;

vector<int> getMinMatrixValuePos(int matrix[][4], int rows)
{
    int minValue = 9999999;
    vector<int> minValuePos = {0, 0};
    for (int i = 0; i < rows; i++)
    {
        for (int l = 0; l < 4; l++)
        {
            int value = matrix[i][l];
            if (value < minValue)
            {
                minValue = value;
                minValuePos[0] = i;
                minValuePos[1] = l;
            }
        }
    }
    return minValuePos;
}

int main()
{
    int rows = 5;
    int matrix[rows][4] = {{1, 2, 3, 5}, {3, 5, 1, 6}, {9, 4, 2, 2}, {0, 1, 3, 8}, {9, 2, 3, 5}};
    vector<int> minValuePos = getMinMatrixValuePos(matrix, rows);
    cout << "The row is: " << minValuePos[0] << endl
         << "and the column is: " << minValuePos[1] << endl;
    return 0;
}