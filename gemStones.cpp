#include <iostream>

using namespace std;

void setBool(bool array[], bool value) {
    for (int i = 0; i < 26; ++i) {
        array[i] = value;
    }
}

int main() {
    int N;
    cin >> N;
    char stones[N][100];
    for (int i = 0; i < N; ++i) {
        cin >> stones[i];
    }

    bool gem[26];
    setBool(gem, true);

    for (int i = 0; i < N; ++i) {
        bool present[26];
        setBool(present, false);
        for (int j = 0; j < 100; ++j) {
            if (stones[i][j] > 96 && stones[i][j] < 123) {
                present[stones[i][j] - 97] = true;
            }
        }
        for (int j = 0; j < 26; ++j) {
            gem[j] = gem[j] & present[j];
        }
    }

    int gemNum = 0;
    for (int i = 0; i < 26; ++i) {
        if (gem[i]) {
            ++gemNum;
        }
    }
    cout << gemNum << endl;
}
