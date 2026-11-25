
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string text;

    ofstream out("welcome.txt");

    out << "Hello Everybody";

    out.close();

    ifstream in("welcome.txt");

    getline(in, text);

    in.close();

    int pos = text.find("body");

    if (pos != string::npos)
    {
        text.replace(pos, 4, "one");
    }

    ofstream file("welcome.txt");

    file << text;

    file.close();

    cout << text;

    return 0;
}
