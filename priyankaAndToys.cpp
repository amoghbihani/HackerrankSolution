#include <iostream>

using namespace std;

void sort(int array[], int first, int last) {
    if (first >= last) {
        return;
    }
    int size = last - first + 1;
    int pivot = first + size / 2;
    int tempArray[size];
    int leftPos = 0, rightPos = size;
    for (int i = first; i <= last; ++i) {
        if (i == pivot) {
            continue;
        }
        if (array[i] <= array[pivot]) {
            tempArray[leftPos++] = array[i];
        } else {
            tempArray[--rightPos] = array[i];
        }
    }
    tempArray[leftPos] = array[pivot];
    for (int i = 0; i < size; ++i) {
        array[first + i] = tempArray[i];
    }
    sort(array, first, first + leftPos - 1);
    sort(array, first + leftPos + 1, last);
}

int main() {
    int N;
    cin >> N;
    int array[N];
    for (int i = 0; i < N; ++i) {
        cin >> array[i];
    }
    sort(array, 0, N - 1);
    int toyWeight = array[0];
    int numBoughtToys = 1;
    for (int i = 0; i < N; ++i) {
        if (array[i] > toyWeight + 4) {
            toyWeight = array[i];
            ++numBoughtToys;
        }
    }
    cout << numBoughtToys << endl;
}
