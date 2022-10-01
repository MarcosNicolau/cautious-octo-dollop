#include <iostream>
#include "./lists.hpp"
#include "../../utils/index.hpp"

using namespace std;

struct Student
{
    string name;
    int legacy;
    double grade;
};

bool grades_criteria(Student a, Student b)
{
    return a.grade > b.grade ? true : false;
};

void printStudents(Node<Student> *node)
{
    Student data = node->data;
    cout << data.name << "\t"
         << "(legacy: " << data.legacy << ")"
         << "\t"
         << ": " << data.grade << endl;
};

bool extractUnableStudents(Student student)
{
    return student.legacy == 847 || student.legacy == 418 || student.legacy == 325;
};

int main()
{
    // All the students that were selected for the congress
    Student _students[9] = {"Maria", 721, 8.4, "Pedro", 847, 7.2, "Ana", 614, 9.1, "Jose", 578, 8.9, "Juan", 927, 8.4, "Unai", 325, 8.1, "Ramon", 418, 8.4, "Elaia", 892, 9.6, "Carlos", 733, 8.5};
    // Students that can't go to the congress
    Student _unable_stds[3] = {"Pedro", 847, 7.2, "Ramon", 418, 8.4, "Unai", 325, 8.1};

    // EX A: List of students sorted by grades
    printDelimiter();
    cout << "List of selected students ordered by grades" << endl;
    OrderedList<Student> students(grades_criteria);
    students.bulkPush(_students, 9);
    students.print(printStudents);

    // EX B: print unable students unordered and then ordered
    printDelimiter();
    cout << "List of students that can't go" << endl;
    Stack<Student> u_unable_stds;
    u_unable_stds.bulkPush(_unable_stds, 3);
    u_unable_stds.print(printStudents);

    // EX C:
    printDelimiter();
    students.extract(extractUnableStudents);
    students.print(printStudents);
};