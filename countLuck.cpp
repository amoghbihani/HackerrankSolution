#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Point {
    int x;
    int y;
} start, last;

int N, M, K;
int map[100][100];
vector<Point> stack;

Point createPoint(int x, int y) {
    Point temp = {x, y};
    return temp;
}

void updatePoint(Point* point, int x, int y) {
    point->x = x;
    point->y = y;
}

bool isSameNode(Point p1, Point p2) {
    return (p1.x == p2.x && p1.y == p2.y);
}

bool isLastNode(Point node) {
    return isSameNode(node, last);
}

void visitNode(Point node) {
    if (isLastNode(node)) {
        return;
    }
    int x = node.x;
    int y = node.y;
    map[x][y] = 1;
    int neighbour = 0;
    Point next;
    if (x > 0 && !map[x - 1][y]) {
        ++neighbour;
        updatePoint(&next, x - 1, y);
    }
    if (y > 0 && !map[x][y - 1]) {
        ++neighbour;
        updatePoint(&next, x, y - 1);
    }
    if (x < N - 1 && !map[x + 1][y]) {
        ++neighbour;
        updatePoint(&next, x + 1, y);
    }
    if (y < M - 1 && !map[x][y + 1]) {
        ++neighbour;
        updatePoint(&next, x, y + 1);
    }
    if (neighbour > 1) {
        if (!stack.size() || !isSameNode(node, stack.back())) {
            stack.push_back(node);
        }
    } else if (!neighbour) {
        if (isSameNode(node, stack.back())) {
            stack.pop_back();
        }
        next = stack.back();
    }
    visitNode(next);
}

void traverseMap() {
    visitNode(start);
    if (stack.size() == K) {
        cout << "Impressed" << endl;
    } else {
        cout << "Oops!" << endl;
    }
}

void getInput() {
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        string str;
        cin >> str;
        for (int j = 0; j < M; ++j) {
            int val;
            if (str.at(j) == '.') {
                val = 0;
            } else if (str.at(j) == 'X' || str.at(j) == 'x') {
                val = 1;
            } else if (str.at(j) == 'M' || str.at(j) == 'm') {
                val = 1;
                updatePoint(&start, i, j);
            } else if (str.at(j) == '*') {
                val = 0;
                updatePoint(&last, i, j);
            }
            map[i][j] = val;
        }
    }
    cin >> K;
}

void reset() {
    stack.clear();
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        reset();
        getInput();
        traverseMap();
    }
}
