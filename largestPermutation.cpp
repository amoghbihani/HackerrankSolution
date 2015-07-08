#include <iostream>

using namespace std;

long largestNum (long array[], long start, long end) {
    long largest = start;
    for (long i = start; i <= end; ++i) {
        if (array[largest] < array[i])
            largest = i;
    }
    return largest;
}

int main() {
    long N, K;
    cin >> N >> K;
    long array[N];
    for (long i = 0; i < N; ++i) {
        cin >> array[i];
    }

    long swapCount = 0;
    for (long i = 0; i < N && swapCount < K; ++i) {
        long largest = largestNum(array, i, N - 1);
        if (largest != i) {
            long temp = array[i];
            array[i] = array[largest];
            array[largest] = temp;
            ++swapCount;
        }
    }

    for (long i = 0; i < N; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}
