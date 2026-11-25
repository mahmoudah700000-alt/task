
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct Person
{
    string name;
    int age;
};

int main()
{
    int n;

    cout << "Enter number of persons: ";
    cin >> n;

    // Step 1: Save persons in file

    ofstream out("persons.txt");

    for (int i = 0; i < n; i++)
    {
        Person p;

        cout << "Enter name: ";
        cin >> ws;
        getline(cin, p.name);

        cout << "Enter age: ";
        cin >> p.age;

        out << p.name << "," << p.age << endl;
    }

    out.close();

    // Step 2: Load persons into vector

    vector<Person> persons;

    ifstream in("persons.txt");

    Person p;
    string line;

    while (getline(in, line))
    {
        int pos = line.find(",");

        p.name = line.substr(0, pos);
        p.age = stoi(line.substr(pos + 1));

        persons.push_back(p);
    }

    in.close();

    // Find younger and older persons

    if (persons.empty())
        return 0;

    Person younger = persons[0];
    Person older = persons[0];

    for (int i = 1; i < persons.size(); i++)
    {
        if (persons[i].age < younger.age)
            younger = persons[i];

        if (persons[i].age > older.age)
            older = persons[i];
    }

    // Save results

    ofstream result("results.txt");

    result << "Younger person: " << younger.name
           << " Age: " << younger.age << endl;

    result << "Older person: " << older.name
           << " Age: " << older.age << endl;

    result.close();

    cout << "Results saved successfully!";

    return 0;
}
