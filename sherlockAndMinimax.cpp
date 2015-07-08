#include <iostream>

using namespace std;

void sort(int array[], int start, int end) {
    if (start >= end)
        return;

    int size = end - start + 1;
    int temp[size];
    int pivot = (start + end) / 2;
    int left = 0;
    int right = size - 1;
    for (int i = start; i <= end; ++i) {
        if (i == pivot)
            continue;
        if (array[i] < array[pivot])
            temp[left++] = array[i];
        else
            temp[right--] = array[i];
    }
    temp[left] = array[pivot];

    for (int i = 0; i < size; ++i) {
        array[start + i] = temp[i];
    }
    sort(array, start, start + left - 1);
    sort(array, start + left + 1, end);
}

int main() {
    int N;
    cin >> N;
    int array[N];
    for (int i = 0; i < N; ++i) {
        cin >> array[i];
    }
    sort(array, 0, N - 1);
    int P, Q;
    cin >> P >> Q;
    if (P == Q) {
        cout << P << endl;
        return 0;
    }
    int first = N - 1, last = 0;
    for (int i = 0; i < N; ++i) {
        if (array[i] > P) {
            first = i;
            break;
        }
    }
    for (int i = N - 1; i >= 0; --i) {
        if (array[i] < Q) {
            last = i;
            break;
        }
    }
    int maxRange = 0, segment = first - 1;
    for (int i = first; i < last; ++i) {
        int range = array[i + 1] - array[i];
        if (range > maxRange) {
            maxRange = range;
            segment = i;
        }
    }
    int num = (array[segment] + array[segment + 1]) / 2;
    int minDiff = num - array[segment];
    if (first > 0) {
        int tempNum = (array[first - 1] + array[first]) / 2;
        if (tempNum > P) {
            if (tempNum - array[first - 1] > minDiff) {
                num = tempNum;
                minDiff = num - array[first - 1];
            }
        } else if (array[first] - P > minDiff) {
            num = P;
            minDiff = array[first] - P;
        }
    } else if (array[first] - P >= minDiff) {
        num = P;
        minDiff = array[P] - minDiff;
    }

    if (last < N - 1) {
        int tempNum = (array[last] + array[last + 1]) / 2;
        if (tempNum < Q) {
            if (tempNum - array[last] > minDiff) {
                num = tempNum;
                minDiff = num - array[last];
            }
        } else if (Q - array[last] > minDiff) {
            num = Q;
            minDiff = Q - array[last];
        }
    } else if (Q - array[last] > minDiff) {
        num = Q;
        minDiff = Q - array[last];
    }

    cout << num << endl;
}
