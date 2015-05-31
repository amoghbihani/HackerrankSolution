#include <iostream>
#include <cstring>

using namespace std;

// ascii of a = 97;

bool hasPalindromeAnagram(string str) {
    int size = str.length();
    int chars[26];
    for (int i = 0; i < 26; ++i)
        chars[i] = 0;
    for (int i = 0; i < size; ++i)
        ++chars[str.at(i) - 97];
    int acceptableOdd = size % 2;
    for (int i = 0; i < 26; ++i) {
        if (chars[i] % 2)
            --acceptableOdd;
        if (acceptableOdd < 0)
            return false;
    }
    return true;
}

int main() {
    string str;
    cin >> str;
    if (hasPalindromeAnagram(str))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
