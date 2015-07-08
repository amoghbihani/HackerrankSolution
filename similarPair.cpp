#include <iostream>
#include <cmath>

using namespace std;

int similarPairs(int Tree[], int size, int T) {
    int ans = 0;
    for (int i = 0; i < size; ++i) {
        int parent = Tree[i];
        while (parent != -1) {
            if (abs(parent - i) <= T)
                ++ans;
            parent = Tree[parent];
        }
    }
    return ans;
}

int main() {
    int N, T;
    cin >> N >> T;
    int Tree[N];
    for (int i = 0; i < N; ++i)
        Tree[i] = -1;
    for (int i = 0; i < N - 1; ++i) {
        int s, e;
        cin >> s >> e;
        Tree[e - 1] = s - 1;
    }
    cout << similarPairs(Tree, N, T) << endl;
}
