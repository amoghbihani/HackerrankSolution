#include <iostream>

using namespace std;

int N;
char Grid[100][100];

void sort(char array[]) {
    for (int i = 0; i < N; ++i) {
        int min = i;
        for (int j = i + 1; j < N; ++j) {
            if (array[j] < array[min]) {
                min = j;
            }
        }
        if (min != i) {
            char temp = array[i];
            array[i] = array[min];
            array[min] = temp;
        }
    }
}

void sortGridRows() {
    for (int i = 0; i < N; ++i) {
        sort(Grid[i]);
    }
}

void createGrid() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> Grid[i][j];
        }
    }
}

void printGrid() {
    cout << "----------------" << endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << Grid[i][j];
        }
        cout << endl;
    }
}

bool isGridColumnsSorted() {
    for (int i = 0; i < N; ++i) {
        for (int j = 1; j < N; ++j) {
            if (Grid[j][i] < Grid[j - 1][i]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        createGrid();
        sortGridRows();
        if (isGridColumnsSorted()) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        // printGrid();
    }
}
