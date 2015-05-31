#include <iostream>
#include <cmath>

using namespace std;

bool isDivisible(long array[], int I, int J, long X) {
    long val = array[I];
    for (int i = I + 1; i <= J && val < X; ++i) {
        val = (long) pow(val, array[i]);
    }
    return !(val % X);
}

int main() {
    int N;
    cin >> N;
    long array[N];
    for (int i = 0; i < N; ++i) {
        cin >> array[i];
    }
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        int I, J;
        long X;
        cin >> I >> J >> X;
        if (isDivisible(array, I - 1, J - 1, X)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}
