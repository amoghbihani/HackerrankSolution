#include <cmath>
#include <iostream>

using namespace std;

int getCliqueSize(int N, int M) {
    return (3 + sqrt(9 + 8 * (M - N + 1))) / 2;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int N, M;
        cin >> N >> M;
        cout << getCliqueSize(N, M) << endl;
    }
}
