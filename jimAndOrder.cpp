#include <iostream>

using namespace std;

struct order {
    int id;
    int time;
};

void sortForTime(order array[], int first, int last) {
    if (first >= last)
        return;

    int size = last - first + 1;
    order temp[size];
    int pivot = first + size / 2;
    int left = 0, right = size - 1;
    for (int i = 0; i < size; ++i) {
        if (i + first == pivot)
            continue;

        if (array[i + first].time < array[pivot].time)
            temp[left++] = array[i + first];
        else
            temp[right--] = array[i + first];
    }
    temp[left] = array[pivot];

    for (int i = 0; i < size; ++i) {
        array[first + i] = temp[i];
    }

    sortForTime(array, first, first + left - 1);
    sortForTime(array, first + left + 1, last);
}

void sortForId(order array[], int first, int last) {
    if (first >= last)
        return;

    int size = last - first + 1;
    order temp[size];
    int pivot = first + size / 2;
    int left = 0, right = size - 1;
    for (int i = 0; i < size; ++i) {
        if (i + first == pivot)
            continue;

        if (array[i + first].id < array[pivot].id)
            temp[left++] = array[i + first];
        else
            temp[right--] = array[i + first];
    }
    temp[left] = array[pivot];

    for (int i = 0; i < size; ++i) {
        array[first + i] = temp[i];
    }

    sortForId(array, first, first + left - 1);
    sortForId(array, first + left + 1, last);
}

void sortOrders(order array[], int N) {
    sortForTime(array, 0, N - 1);
    for (int i = 0; i < N; ++i) {
        int j = i;
        while (i < N - 1 && array[i + 1].time == array[i].time) {
            ++i;
        }
        if (j != i) {
            sortForId(array, j, i);
        }
    }
}

int main() {
    int N;
    cin >> N;
    order list[N];
    for (int i = 0 ; i < N; ++i) {
        int t, d;
        cin >> t >> d;
        list[i].id = i;
        list[i].time = t + d;
    }
    sortOrders(list, N);
    for (int i = 0; i < N; ++i) {
        cout << list[i].id + 1 << " ";
    }
}
