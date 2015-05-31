#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> edge;
vector<edge> tree;

edge getEmptyEdge() {
    edge temp;
    return temp;
}

int makeForest() {
    bool edgeDeleted = false;
    int numEdgesDeleted = 0;
    do {
        edgeDeleted = false;
        for (int i = tree.size() - 1; i > 0; --i) {
            if (tree[i].size() % 2 == 0) {
                int parent = i;
                for (int j = 0; j < tree[i].size(); ++j) {
                    if (tree[i][j] < parent) {
                        parent = tree[i][j];
                    }
                }
                edge::iterator pos = find(tree[i].begin(), tree[i].end(), parent);
                tree[i].erase(pos);
                pos = find(tree[parent].begin(), tree[parent].end(), i);
                tree[parent].erase(pos);
                edgeDeleted = true;
                ++numEdgesDeleted;
            }
        }
    } while(edgeDeleted);
    return numEdgesDeleted;
}

int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 0; i <= N; ++i) {
        tree.push_back(getEmptyEdge());
    }
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    cout << makeForest() << endl;
}
