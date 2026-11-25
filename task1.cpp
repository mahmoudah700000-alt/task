
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string name;
    int id;
    float grade;

    cout << "Enter Full Name: ";
    getline(cin, name);

    cout << "Enter ID: ";
    cin >> id;

    cout << "Enter Grade: ";
    cin >> grade;

    ofstream file("Student.txt");

    file << "Name: " << name << endl;
    file << "ID: " << id << endl;
    file << "Grade: " << grade << endl;

    file.close();

    cout << "Data saved successfully!";

    return 0;
}
