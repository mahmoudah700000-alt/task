
#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

int main()
{
    int grade;

    // Step 1: Create file and write five grades

    ofstream out("grades.txt");

    for (int i = 0; i < 5; i++)
    {
        cout << "Enter grade: ";
        cin >> grade;
        out << grade << endl;
    }

    out.close();

    // Step 2: Read and print grades

    ifstream in("grades.txt");

    cout << "\nGrades before deletion:\n";

    while (in >> grade)
    {
        cout << grade << endl;
    }

    in.close();

    // Step 3: Delete a grade using temporary file

    int deleteGrade;

    cout << "\nEnter grade to delete: ";
    cin >> deleteGrade;

    in.open("grades.txt");
    ofstream temp("temp.txt");

    while (in >> grade)
    {
        if (grade != deleteGrade)
        {
            temp << grade << endl;
        }
    }

    in.close();
    temp.close();

    // Step 4: Replace original file

    if (remove("grades.txt") == 0)
    {
        if (rename("temp.txt", "grades.txt") == 0)
            cout << "\nFile updated successfully!";
        else
            cout << "\nError replacing file!";
    }
    else
    {
        cout << "\nError deleting original file!";
    }

    // Print grades after deletion

    in.open("grades.txt");

    cout << "\n\nGrades after deletion:\n";

    while (in >> grade)
    {
        cout << grade << endl;
    }

    in.close();

    return 0;
}
