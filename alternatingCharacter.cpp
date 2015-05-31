#include <iostream>
#include <cstring>

using namespace std;

int deleteChar(string str) {
    int charsDeleted = 0;
    for (int i = 0; i < str.length() - 1; ++i) {
        if (str.at(i) == str.at(i + 1))
            ++charsDeleted;
    }
    return charsDeleted;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        string str;
        cin >> str;
        cout << deleteChar(str) << endl;
    }
}
