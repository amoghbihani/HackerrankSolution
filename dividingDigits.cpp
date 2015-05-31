#include <cmath>
#include <iostream>

using namespace std;

int numDividingDigits(long N) {
    int tenPower = log10(N) + 1;
    int result = 0;
    for (int i = 1; i <= tenPower; ++i) {
        int digit = N % (long)pow(10, i);
        digit /= (long)pow(10, i -1);
        if (!digit)
            continue;

        if (!(N % digit))
            ++result;
    }
    return result;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        long N;
        cin >> N;
        cout << numDividingDigits(N) << endl;
    }
    return 0;
}
