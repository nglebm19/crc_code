#include <iostream>
using namespace std;

string FirstWord(string s) {
    string out;
    s += ' ';            // sentinel so we always hit a space
    int i = 0;
    while (s[i] != ' ') {
        out += s[i];
        i = i + 1;
    }
    return out;
}

int main() {
    cout << FirstWord("Hello world") << "\n";        // Hello
    cout << FirstWord("   leading spaces ok") << "\n"; // leading
    cout << FirstWord("") << "\n";                   // (empty line)
}