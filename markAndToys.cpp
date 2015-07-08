#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    int values[N][2];
    int min = 0;
    for (int i = 0; i < N; ++i) {
        cin >> values[i][0];
        values[i][1] = 0;
        if (values[i][0] < values[min][0]) {
            min = i;
        }
    }

    values[min][1] = 1;
    int stack = 0;
    for (int i = min + 1; i < N; ++i) {
        if (values[i][0] < values[i - 1][0]) {
            values[i][1] = 1;
            ++stack;
            for (int j = 1; j < stack; ++j) {
                ++values[i - j][1];
            }
            if (values[i - stack][1] == values[i - stack + 1][1]) {
                ++values[i - stack][1];
            }
        } else if (values[i][0] == values[i - 1][0]) {
            values[i][1] = 1;
            stack = 0;
        } else {
            values[i][1] = values[i - 1][1] + 1;
            stack = 0;
        }
    }

    for (int i = min - 1; i > -1; --i) {
        if (values[i][0] < values[i + 1][0]) {
            values[i][1] = 1;
            ++stack;
            for (int j = 1; j < stack; ++j) {
                ++values[i + j][1];
            }
            if (values[i + stack][1] == values[i + stack - 1][1]) {
                ++values[i + stack][1];
            }
        } else if (values[i][0] == values[i + 1][0]) {
            values[i][1] = 1;
            stack = 0;
        } else {
            values[i][1] = values[i + 1][1] + 1;
            stack = 0;
        }
    }

    int count = 0;
    for (int i = 0; i < N; ++i) {
        count += values[i][1];
    }
    cout << count << endl;
}
