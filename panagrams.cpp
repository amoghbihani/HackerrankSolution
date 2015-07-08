#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    char s[1000];
    cin.getline(s, 1000);
    
    bool alphabets[26];
    for (int i = 0; i < 26; ++i) {
        alphabets[i] = false;
    }

    for (int i = 0; i < 1000; ++i) {
        if (s[i] > 64 && s[i] < 91) {
            if (alphabets[s[i] - 65] == false)
                cout << s[i] << " ";
            alphabets[s[i] - 65] = true;
        } else if (s[i] > 96 && s[i] < 123) {
            if (alphabets[s[i] - 96] == false)
                cout << s[i] << " ";
            alphabets[s[i] - 97] = true;
        }
    }
    
    for (int i = 0; i < 26; ++i) {
        if (!alphabets[i]) {
            cout << "not pangram" << endl;
            return 0;
        }
    }
    cout << "pangram" << endl;
    
    return 0;
}
