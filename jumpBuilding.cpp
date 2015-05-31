#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int validRoutes(int height[], int N) {
    int routes = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (height[j] > height[i]) {
                break;
            } else if (height[j] == height[i]) {
                ++routes;
            }
        }
    }
    return routes * 2;
}

int main() {
    int N;
    cin >> N;
    int height[N];
    for (int i = 0; i < N; ++i) {
        cin >> height[i];
    }
    
    cout << validRoutes(height, N) << endl;
    return 0;
}
