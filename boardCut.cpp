#include <iostream>

// #define DEBUG
#define MODULO 1000000007

using namespace std;

#ifdef DEBUG
void printArray(long array[], int size) {
    for (int i = 0; i < size; ++i)
        cout << array[i] << " ";
    cout << endl;
}
#endif

void sort(long array[], int first, int last) {
    if (first >= last)
        return;

    int size = last - first + 1;
    long temp[size];
    int pivot = (first + last) / 2;
    int left = 0, right = size - 1;
    for (int i = 0; i < size; ++i) {
        if (first + i == pivot)
            continue;
        if (array[i + first] > array[pivot])
            temp[left++] = array[i + first];
        else
            temp[right--] = array[i + first];
    }
    temp[left] = array[pivot];

    for (int i = 0; i < size; ++i)
        array[first + i] = temp[i];

    sort(array, first, first + left - 1);
    sort(array, first + left + 1, last);
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int M, N;
        cin >> M >> N;
        M--;
        N--;
        long Y[M];
        long X[N];
        for (int j = 0; j < M; ++j)
            cin >> Y[j];
        for (int j = 0; j < N; ++j)
            cin >> X[j];
        sort(Y, 0, M - 1);
        sort(X, 0, N - 1);
#ifdef DEBUG
        printArray(Y, M);
        printArray(X, N);
#endif
        int y = 0, x = 0;
        long cost = 0;
        while (y < M && x < N) {
            if (Y[y] > X[x]) {
                cost = (cost + ((x + 1) * Y[y++]) % MODULO) % MODULO;
            } else {
                cost = (cost + ((y * 1) * X[x++]) % MODULO) % MODULO;
            }
        }
        while (y < M) {
            cost = (cost + ((N + 1) * Y[y++]) % MODULO) % MODULO;
        }
        while (x < N) {
            cost = (cost + ((M + 1) * X[x++]) % MODULO) % MODULO;
        }
        cout << cost << endl;
    }
}
