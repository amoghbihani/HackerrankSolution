#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

struct Node {
    int value;
    int childrenSum;
    vector<int> neighbour;
};

Node createNode(int value) {
    Node node;
    node.value = value;
    node.childrenSum = value;

    return node;
}

vector<Node> Tree;

void findChildSum(int nodeNum, int parentNum) {
    for (int i = 0; i < Tree[nodeNum].neighbour.size(); ++i) {
        int next = Tree[nodeNum].neighbour[i];
        if (next == parentNum)
            continue;
        findChildSum(next, nodeNum);
        Tree[nodeNum].childrenSum += Tree[next].childrenSum;
    }
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int value;
        cin >> value;
        Tree.push_back(createNode(value));
    }

    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        Tree[a - 1].neighbour.push_back(b - 1);
        Tree[b - 1].neighbour.push_back(a - 1);
    }

    findChildSum(0, -1);
    int halfSum = Tree[0].childrenSum / 2;
    int minDeviation = halfSum;
    for (int i = 0; i < N; ++i) {
        if (abs(halfSum - Tree[i].childrenSum) < minDeviation)
            minDeviation = abs(halfSum - Tree[i].childrenSum);
    }
    cout << 2 * minDeviation;
}
