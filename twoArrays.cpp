#include <iostream>

using namespace std;

int N, K;
int A[1000];
int B[1000];

void sort(int array[]) {
    for (int i = 0; i < N; ++i) {
        int min = i;
        for (int j = i + 1; j < N; ++j) {
            if (array[j] < array[min]) {
                min = j;
            }
        }
        if (min != i) {
            int temp = array[min];
            array[min] = array[i];
            array[i] = temp;
        }
    }
}

void getInput() {
    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> B[i];
    }
}

void checkSumCondition() {
    for (int i = 0; i < N; ++i) {
        if (A[i] + B[N - i - 1] < K) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        getInput();
        sort(A);
        sort(B);
        checkSumCondition();
    }
}
