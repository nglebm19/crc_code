// Name: Andrew Le

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int countLines(const string& fileName) {
    ifstream in(fileName);
    if (in.fail()) {
        return 0;
    }

    int lines = 0;
    string temp;
    while (getline(in, temp)) {
        lines++;
    }

    in.close();
    return lines;
}

int main() {
    string fileName = "notes.txt";

    ofstream out(fileName);
    if (out.fail()) {
        cout << "Error opening file for writing.\n";
        return 1;
    }

    out << "Line 1: Hello from Lab09!" << '\n';
    out << "Line 2: We are practicing file I/O." << '\n';
    out << "Line 3: Counting lines is useful." << '\n';
    out << "Line 4: Reading them back with getline()." << '\n';

    out.close();

    int numLines = countLines(fileName);

    ifstream in(fileName);
    if (in.fail()) {
        cout << "Error opening file for reading.\n";
        return 1;
    }

    cout << "Reading " << numLines << " line(s):" << endl;

    string line;
    while (getline(in, line)) {
        cout << line << endl;
    }

    in.close();
    return 0;
}
