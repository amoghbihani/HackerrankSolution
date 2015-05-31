#include <iostream>
#include <math.h>

using namespace std;

bool isKaprekarNumber(int num) {
    long squareNum = num * num;
    int leftDigits = (int) log10(num) + 1;
    int left = squareNum % (int) pow(10, leftDigits);
    int right = squareNum / (int) pow(10, leftDigits);
    return left + right == num;
}

int main() {
    int low, high;
    cin >> low >> high;
    for (int i = low; i <= high; ++i) {
        if (isKaprekarNumber(i))
            cout << i << " ";
    }
}
