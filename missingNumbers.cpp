#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void sort(int array[], int first, int last) {
    if (last <= first) {
        return;
    }

    int size = last - first + 1;
    int temp[size];
    int pivot = first + (size / 2);
    int front = 0, back = 0;
    for (int i = 0; i < size; ++i) {
        if (i == size / 2) {
            continue;
        }
        if (array[i + first] <= array[pivot]) {
            temp[front] = array[i + first];
            ++front;
        } else {
            temp[size - back - 1] = array[i + first];
            ++back;
        }
    }
    temp[front] = array[pivot];
    for (int i = 0; i < size; ++i) {
        array[i + first] = temp[i];
    }
    sort(array, first, first + front - 1);
    sort(array, first + front, last);
}

int main() {
    int N, M;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    cin >> M;
    int B[M];
    for (int i = 0; i < M; ++i) {
        cin >> B[i];
    }
    sort(A, 0, N - 1);
    sort(B, 0, M - 1);
    int absent = B[0] - 1;
    for (int i = 0, j = 0; i < M; ++i) {
        if (B[i] == A[j]) {
            ++j;
        } else if (B[i] != absent) {
            absent = B[i];
            cout << absent << " ";
        }
    }
    cout << endl;
    return 0;
}
