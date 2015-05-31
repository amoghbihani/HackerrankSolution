#include <iostream>

using namespace std;

void sort(int array[], int first, int last) {
    if (first >= last)
        return;

    int size = last - first + 1;
    int temp[size];
    int pivot = first + size / 2;
    int left = 0, right = size - 1;
    for (int i = 0; i < size; ++i) {
        if (i + first == pivot)
            continue;
        if (array[i + first] > array[pivot])
            temp[left++] = array[i + first];
        else
            temp[right--] = array[i + first];
    }
    temp[left] = array[pivot];

    for (int i = 0; i < size; ++i) {
        array[first + i] = temp[i];
    }

    sort(array, first, first + left - 1);
    sort(array, first + left + 1, last);
}

int main() {
    int N, K;
    cin >> N >> K;
    int cost[N];
    for (int i = 0; i < N; ++i) {
        cin >> cost[i];
    }
    sort(cost, 0, N - 1);
    long amount = 0;
    int blocks = N / K;
    for (int i = 0; i < blocks; ++i) {
        for (int j = K * i; j < K * (i + 1); ++j) {
            amount += cost[j] * (i + 1);
        }
    }
    for (int i = blocks * K; i < N; ++i) {
        amount += cost[i] * (blocks + 1);
    }
    cout << amount << endl;
}
