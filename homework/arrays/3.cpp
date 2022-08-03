#include <iostream>
#include <vector>
#include "utils.h"

using namespace std;

float getAllMarksAverage(vector<float> marks)
{
    return getAverage(getVectorElementsSum(marks), marks.size());
}

float getAboveAverageMarks(vector<float> marks, float average)
{
    int counter = 0;
    for (int i = 0; i < marks.size(); i++)
    {
        float mark = marks[i];
        if (isNumberBigger(mark, average))
            counter++;
    }
    return counter;
}

int main()
{
    vector<float> marks = createNumberVectorFromFile("3.txt");
    float average = getAllMarksAverage(marks);
    int aboveAverageMarks = getAboveAverageMarks(marks, average);
    cout << "The marks average is " << average << endl;
    cout << "The number of students with above average marks are " << aboveAverageMarks << endl;
    return 0;
}