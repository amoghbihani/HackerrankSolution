#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;
    int map[N][N];
    for (int i = 0; i < N; ++i) {
        int depthRow;
        cin >> depthRow;
        for (int j = 0; j < N; ++j) {
            int value = depthRow % (int)pow(10, j + 1);
            value /= pow(10, j);
            map[i][N - j - 1] = value;
        }
    }

    for (int i = 1; i < N - 1; ++i) {
        for (int j = 1; j < N - 1; ++j) {
            if (map[i][j - 1] >= map[i][j])
                continue;
            if (map[i][j + 1] >= map[i][j])
                continue;
            if (map[i - 1][j] >= map[i][j])
                continue;
            if (map[i + 1][j] >= map[i][j])
                continue;
            map[i][j] = 10;
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (map[i][j] == 10)
                cout << "X";
            else
                cout << map[i][j];
        }
        cout << endl;
    }
}
