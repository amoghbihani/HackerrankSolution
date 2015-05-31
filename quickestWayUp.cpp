#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

struct Element {
    int start;
    int end;
    int length;
};

Element getElement(int start, int end) {
    Element element;
    element.start = start;
    element.end = end;
    element.length = abs(start - end);
    return element;
}

vector<Element> ladders;
vector<Element> snakes;
vector<Element> favourablePoints;
vector<int> avoidPoints;

void findPoints() {
    while (ladders.size()) {
        int longest = 0;
        for (int i = 0; i < ladders.size(); ++i) {
            if (ladders[i].length > ladders[longest].length) {
                longest = i;
            }
        }
        bool isFavourable = true;
        for (int i = 0; i < favourablePoints.size(); ++i) {
            int tempStart, tempEnd;
            tempStart = ladders[longest].start;
            tempEnd = ladders[longest].end;
            if ((tempEnd < favourablePoints[i].end && tempEnd > favourablePoints[i].start)
                    || (tempStart > favourablePoints[i].start && tempStart < favourablePoints[i].end)) {
                isFavourable = false;
                break;
            }
        }
        if (isFavourable) {
            favourablePoints.push_back(ladders[longest]);
        } else {
            avoidPoints.push_back(ladders[longest].start);
        }
        ladders.erase(ladders.begin() + longest);
    }
    favourablePoints.push_back(getElement(100, 100));
    for (int i = 0; i < snakes.size(); ++i) {
        avoidPoints.push_back(snakes[i].start);
    }
}

bool isUnacceptablePoint(int point) {
    return find(avoidPoints.begin(), avoidPoints.end(), point) != avoidPoints.end();
}

int findChances(int start, int end) {
    int chances = 0, pos = start;
    while (pos != end) {
        ++chances;
        if (pos + 6 >= end) {
            pos = end;
        } else {
            int tempPos = pos + 6;
            while (isUnacceptablePoint(tempPos)) {
                --tempPos;
            }
            if (tempPos == pos) {
                return -1;
            } else {
                pos = tempPos;
            }
        }
    }
    return chances;
}

int findMinimumChances() {
    findPoints();
    int chances = findChances(0, favourablePoints[0].start);
    if (chances == -1) {
        return -1;
    }
    for (int i = 1; i < favourablePoints.size(); ++i) {
        int tempChances = findChances(favourablePoints[i - 1].end, favourablePoints[i].start);
        if (tempChances == -1) {
            return -1;
        }
        chances += tempChances;
    }
    return chances;
}

void getInput() {
    int N, M;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int start, end;
        cin >> start >> end;
        ladders.push_back(getElement(start, end));
    }
    cin >> M;
    for (int i = 0; i < M; ++i) {
        int start, end;
        cin >> start >> end;
        snakes.push_back(getElement(start, end));
    }
}

void reset() {
    ladders.clear();
    snakes.clear();
    favourablePoints.clear();
    avoidPoints.clear();
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        reset();
        getInput();
        cout << findMinimumChances() << endl;
    }
}
