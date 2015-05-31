#include <iostream>

using namespace std;

int N;
int series[100000];
bool hasPositive;

int maxElement() {
    int max = series[0];
    for (int i = 0; i < N; ++i) {
        if (max < series[i])
            max = series[i];
    }
    return max;
}

long maxContiguousSum() {
    if (!hasPositive)
        return maxElement();

    long sum ;
    long maxSum = 0;
    int i = 0;
    while (i < N) {
        for (; i < N && series[i] <= 0; ++i) { }
        sum = 0;
        while (sum >= 0 && i < N) {
            sum += series[i++];
            if (sum > maxSum)
                maxSum = sum;
        }
    }
    return maxSum;
}

long maxSum() {
    if (!hasPositive)
        return maxElement();

    long sum = 0;
    for (int i = 0; i < N; ++i) {
        if (series[i] > 0)
            sum += series[i];
    }
    return sum;
}

void getInput() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> series[i];
        if (!hasPositive && series[i] > 0)
            hasPositive = true;
    }
}

void reset() {
    hasPositive = false;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        reset();
        getInput();
        cout << maxContiguousSum() << " ";
        cout << maxSum() << endl;
    }
}
