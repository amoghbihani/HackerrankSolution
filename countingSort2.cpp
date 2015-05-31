#include <iostream>

using namespace std;

int NUM_KEYS = 100;

void reset(int keys[]) {
    for (int i = 0; i < NUM_KEYS; ++i) {
        keys[i] = 0;
    }
}

int main() {
    int N;
    cin >> N;
    int keys[NUM_KEYS];
    reset(keys);
    for (int i = 0; i < N; ++i) {
        int value;
        cin >> value;
        if (value >= NUM_KEYS) {
            continue;
        }
        ++keys[value];
    }
    for (int i = 0; i < NUM_KEYS; ++i) {
        for (int j = 0; j < keys[i]; ++j) {
            cout << i << " ";
        }
    }
    cout << endl;
}
