#include <iostream>

using namespace std;

long leftSum;
long rightSum;
int array[100000];
int N;

bool IsEqualSumPossible() {
    rightSum -= array[0];
    for (int i = 1; i < N; ++i) {
        leftSum += array[i - 1];
        rightSum -= array[i];
        if (leftSum == rightSum)
            return true;
    }
    if (rightSum == leftSum)
        return true;
    return false;
}

void createArray() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> array[i];
        rightSum += array[i];
    }
}

void reset() {
    leftSum = 0;
    rightSum = 0;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        reset();
        createArray();
        if (IsEqualSumPossible())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
