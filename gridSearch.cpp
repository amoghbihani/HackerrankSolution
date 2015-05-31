#include <iostream>
#include <stdlib.h>

using namespace std;

int array[1000][1000];
int pattern[1000][1000];
int R, C, r, c;

bool patternMatches(int x, int y) {
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (array[i + x][j + y] != pattern[i][j])
                return false;
        }
    }
    return true;
}

bool isPatternPresent() {
    for (int i = 0; i <= R - r; ++i) {
        for (int j = 0; j <= C - c; ++j) {
            if (array[i][j] == pattern[0][0] && patternMatches(i, j)) {
                    return true;
            }
        }
    }
    return false;
}

void getInput() {
    cin >> R >> C;
    for (int i = 0; i < R; ++i) {
       for (int j = 0; j < C; ++j) {
           char ch;
           cin >> ch;
           array[i][j] = atoi(&ch);
       }
    }
    cin >> r >> c;
    for (int i = 0; i < r; ++i) {
       for (int j = 0; j < c; ++j) {
           char ch;
           cin >> ch;
           pattern[i][j] = atoi(&ch);
       }
    }
}

void reset() {
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        reset();
        getInput();
        if (isPatternPresent())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
