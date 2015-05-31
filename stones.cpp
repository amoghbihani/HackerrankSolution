#include <iostream>

using namespace std;

void printPossibleValues(int N, int A, int B) {
    if (A == B) {
        cout << (N - 1) * A;
        return;
    }
    int small, large;
    if (A < B) {
        small = A;
        large = B;
    } else {
        small = B;
        large = A;
    }
    for (int i = 0; i < N; ++i) {
        cout << i * large + (N - i - 1) * small << " ";
    }
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int N, A, B;
        cin >> N >> A >> B;
        printPossibleValues(N, A, B);
        cout << endl;
    }
    return 0;
}
