#include <iostream>
#include <string>

using namespace std;

int PIE[] = { 3, 1, 4, 1, 5, 9, 2, \
              6, 5, 3, 5, 8, 9, 7, \
              9, 3, 2, 3, 8, 4, 6, \
              2, 6, 4, 3, 3, 8, 3, 3 };

bool isPiSong() {
    int i = 0, length = 0;
    char ch;
    cin.get(ch);
    bool acceptable = true;
    while ( ch != '\n'){
        if (ch == ' ') {
            if (length != PIE[i]) {
                acceptable = false;
            } else {
                ++i;
                length = 0;
            }
        } else {
            ++length;
        }
        cin.get(ch);
    };
    return acceptable && length == PIE[i];
}

int main() {
    int T;
    cin >> T;
    char ch;
    cin.get(ch); // dummy to eat up 'enter'.
    for (int i = 0; i < T; ++i) {
        if (isPiSong()) {
            cout << "It's a pi song." << endl;
        } else {
            cout << "It's not a pi song." << endl;
        }
    }
}
