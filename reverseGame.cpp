#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int N, K;
        cin >> N >> K;
        if (K < (N - 1) / 2) {
            cout << K * 2 + 1 << endl;
        } else {
            cout << (N - 1 - K) * 2 << endl;
        }
    }
}
