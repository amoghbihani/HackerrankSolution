#include <iostream>

using namespace std;

void sort(long array[], long start, long end) {
    if (start >= end)
        return;

    long pivot = (start + end) / 2;
    long size = end - start + 1;
    long temp[size];
    long left = 0, right = size - 1;
    for (long i = 0; i < size; ++i) {
        if (start + i == pivot)
            continue;

        if (array[i + start] < array[pivot])
            temp[left++] = array[i + start];
        else
            temp[right--] = array[i + start];
    }
    temp[left] = array[pivot];

    for (long i = 0; i < size; ++i) {
        array[start + i] = temp[i];
    }
    sort(array, start, start + left - 1);
    sort(array, start + left + 1, end);
}

int main() {
    long N, K;
    cin >> N >> K;
    long array[N];
    for (long i = 0; i < N; ++i) {
        cin >> array[i];
    }
    sort(array, 0, N - 1);
    long blockNum = array[0] / K, ans = 0;
    long firstPointer = 0, secondPointer = 0;
    for (long i = 0; i < N; ++i) {
        if (array[i] >= (blockNum + 1) * K) {
            secondPointer = i;
            ++blockNum;
            break;
        }
    }
    long thirdPointer = secondPointer;
    for (long i = secondPointer; i < N;) {
        long nextBlock = (blockNum + 1) * K;
        for (; i < N; ++i) {
            if (array[i] >= nextBlock)
                break;
        }
        thirdPointer = i;
        for (; firstPointer != secondPointer; ++firstPointer) {
            for (long tempPointer = secondPointer; tempPointer < thirdPointer; ++tempPointer) {
                if (array[tempPointer] - array[firstPointer] == K) {
                    ++ans;
                }
            }
        }
        firstPointer = secondPointer;
        secondPointer = thirdPointer;
        ++blockNum;
    }
    cout << ans << endl;
}
