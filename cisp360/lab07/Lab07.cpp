// Name: Andrew Le

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::getline;
using std::string;

int CountVowels(string s);
int CountUpper(string s);
int CountLower(string s);
string FirstWord(string s);   
string ModifyString(string s);

int main() {
    string sentence;

    cout << "Enter sentence: ";
    getline(cin, sentence);

    int vowels = CountVowels(sentence);
    int uppers = CountUpper(sentence);
    int lowers = CountLower(sentence);
    string first = FirstWord(sentence);
    string modified = ModifyString(sentence);

    cout << "Vowels count: " << vowels << "\n";
    cout << "Upper count: " << uppers << "\n";
    cout << "Lower count: " << lowers << "\n";
    cout << "First word: " << first << "\n";
    cout << "Modified string: " << modified << "\n";

    return 0;
}

int CountVowels(string s) {
    int count = 0;
    for (char c : s) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            count++;
        }
    }
    return count;
}

int CountUpper(string s) {
    int count = 0;
    for (char c : s) {
        if (c >= 'A' && c <= 'Z') {
            count++;
        }
    }
    return count;
}

int CountLower(string s) {
    int count = 0;
    for (char c : s) {
        if (c >= 'a' && c <= 'z') {
            count++;
        }
    }
    return count;
}

string FirstWord(string s) {
    string out = "";
    int i = 0;
    while (s[i] != ' ') {
        out += s[i];
        i += 1;
    }
    return out;
}

string ModifyString(string s) {
    return s + "!!!";
}
