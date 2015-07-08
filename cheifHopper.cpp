#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    int height[N];
    long botEnergy = 0;
    for (int i = 0; i < N; ++i) {
        cin >> height[i];
        if (height[i] > botEnergy)
            botEnergy = height[i];
    }

    int start = 0, end = botEnergy;
    while (start < end) {
        bool satisfied = true;
        botEnergy = (start + end) / 2;
        for (int i = 0; i < N; ++i) {
            botEnergy = (2 * botEnergy - height[i]) % 1000000007;
            if (botEnergy < 0) {
                start = (start + end) / 2 + 1;
                satisfied = false;
                break;
            }
        }
        if (satisfied) {
            end = (start + end) / 2;
        }
    }
    cout << start << endl;
}
