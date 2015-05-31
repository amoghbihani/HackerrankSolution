#include <iostream>
#include <vector>

using namespace std;

struct Point {
    int x;
    int y;
};

Point createPoint(int x, int y) {
    Point point = {x, y};
    return point;
}

void updatePoint(Point* point, int x, int y) {
    point->x = x;
    point->y = y;
}

int M, N, maxCount, visitedX, visitedY, count;
int map[10][10];
vector<Point> stack;

void visitNode(Point);

void findRegion() {
    for (int i = visitedX; i < M; ++i) {
        for (int j = visitedY; j < N; ++j) {
            if (map[i][j] == 1) {
                visitedX = i;
                visitedY = j;
                visitNode(createPoint(i, j));
                return;
            }
        }
    }    
}

void visitNode(Point node) {
    int x = node.x;
    int y = node.y;
    Point next;
    if (map[x][y] == 1) {
        ++count;
    }
    map[x][y] = 2;
    if (x > 0 && map[x - 1][y] == 1) {
        updatePoint(&next, x - 1, y);
    } else if (x > 0 && y > 0 && map[x - 1][y - 1] == 1) {
        updatePoint(&next, x - 1, y - 1);
    } else if (x > 0 && y < N - 1 && map[x - 1][y + 1] == 1) {
        updatePoint(&next, x - 1, y + 1);
    } else if (y > 0 && map[x][y - 1] == 1) {
        updatePoint(&next, x, y - 1);
    } else if (y < N - 1 && map[x][y + 1]) {
        updatePoint(&next, x,  y + 1);
    } else if (x < M - 1 && map[x + 1][y] == 1) {
        updatePoint(&next, x + 1, y);
    } else if (x < M - 1 && y > 0 && map[x + 1][y - 1] == 1) {
        updatePoint(&next, x + 1, y - 1);
    } else if (x < M - 1 && y < N -1 && map[x + 1][y + 1] == 1) {
        updatePoint(&next, x + 1, y - 1);
    } else {
        if (stack.size()) {
            next = stack.back();
            stack.pop_back();
        } else {
            if (count > maxCount) {
                maxCount = count;
            }
            count = 0;
            findRegion();
            return;
        }
    }
    if (map[next.x][next.y] == 1) {
        stack.push_back(node);
    }
    visitNode(next);
}

void getInput() {
    cin >> M >> N;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> map[i][j];
        }
    }
}

void reset() {
    stack.clear();
    maxCount = 0;
    count = 0;
    visitedX = 0;
    visitedY = 0;
}

int main() {
    reset();
    getInput();
    findRegion();
    cout << maxCount << endl;
}
