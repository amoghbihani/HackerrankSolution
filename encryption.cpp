#include <cmath>
#include <string>
#include <iostream>

using namespace std;

int main() {
    string str;
    cin >> str;
    int length = str.length();
    float sqroot = sqrt(length);
    int row = floor(sqroot);
    int col = ceil(sqroot);
    if (row * col < length) {
        row = col;
    }
    char array[row][col];
    for (int i = 0; i < length; ++i) {
        array[i / col][i % col] = str.at(i);
    }
    for (int i = 0; i < col; ++i) {
        for (int j = 0; j < row; ++j) {
            if (i + (j * col) >= length) {
                continue;
            }
            cout << array[j][i];
        }
        cout << " ";
    }
    return 0;
}
