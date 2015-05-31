#include <cmath>
#include <iostream>
#include <string>

using namespace std;

void makePallindrome(char input[], int length) {
    int operations = 0;
    for(int i = 0; i < length / 2; ++i) {
        operations += abs(input[i] - input[length - i - 1]);
    }
    cout << operations << endl;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        char input[10000];
        cin >> input;
        int length = 0;
        for (; (int)input[length]; ++length) {}
        makePallindrome(input, length);
    }
    return 0;
}
