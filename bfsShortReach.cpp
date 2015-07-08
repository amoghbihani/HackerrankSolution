#include <iostream>

using namespace std;

struct Node {
    int adjacent[1000];
    int neighbors;
    int distance;
};

Node createNode() {
    Node node;
    node.neighbors = 0;
    node.distance = -1;
    for (int i = 0; i < 1000; ++i) {
        node.adjacent[i] = 0;
    }
    return node;
}

int min(int a, int b) {
    if (b == -1) {
        return a;
    }

    if (a < b) {
        return a;
    }

    return b;
}

int N, S;

Node tree[1000];
bool visited[1000];

int queue[1000000];
int currentPos;
int queueLength;

void showDistance() {
    for (int i = 0; i < N; ++i) {
        if (i == S) {
            continue;
        }
        cout << tree[i].distance << " ";
    }
}

void setDistance(int id) {
    if (visited[id]) {
        return;
    }
    visited[id] = true;
    for (int i = 0; i < tree[id].neighbors; ++i) {
        int next = tree[id].adjacent[i];
        if (next >= N)
            continue;
        tree[next].distance = min(tree[id].distance + 6, tree[next].distance);
        queue[queueLength++] = next;
    }
}

void findRoutes() {
    tree[S].distance = 0;
    currentPos = 0;
    queue[queueLength++] = S;
    while (currentPos != queueLength) {
        setDistance(queue[currentPos++]);
    }
}

void getInput() {
    int M;
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        tree[i] = createNode();
        visited[i] = false;
    }
    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        tree[x - 1].adjacent[tree[x - 1].neighbors++] = y - 1;
        tree[y - 1].adjacent[tree[y - 1].neighbors++] = x - 1;
    }
    cin >> S;
    S--;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        getInput();
        findRoutes();
        showDistance();
    }
}
