#include <iostream>

using namespace std;

int mod(int value) {
    if (value >= 0)
        return value;
    return value * -1;
}

void checkFunny() {
    char string[1000];
    int length = 0;
    cin.get();
    while(cin.peek() != '\n') {
        cin.get(string[length++]);
    }

    for (int i = 1; i <= length / 2; ++i) {
        if (mod(string[length - i] - string[length - i - 1])
                != mod(string[i] - string[i - 1])) {
            cout << "Not Funny" << endl;
            return;
        }
    }
    cout << "Funny" << endl;
}

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; ++i) {
        checkFunny();
    }
}
