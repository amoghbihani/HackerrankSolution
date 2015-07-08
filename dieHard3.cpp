#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    
    return gcd(b, a % b);
}

int max(int a, int b) {
    if (a > b)
        return a;
    return b;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        int g = gcd(a, b);
        if (c > max(a, b)) {
            if (c == a + b)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
            continue;
        }
        if (c % g)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}
