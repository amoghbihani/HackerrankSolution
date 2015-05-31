#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int leftChild;
    int rightChild;
};

Node createNode(int left, int right) {
    Node temp = {left, right};
    return temp;
}

vector<Node> Tree;

void inOrderTraversal(int index) {
    if (Tree[index].leftChild != -1) {
        inOrderTraversal(Tree[index].leftChild);
    }
    cout << index << " ";
    if (Tree[index].rightChild != -1) {
        inOrderTraversal(Tree[index].rightChild);
    }
}

void swapNodes(int height) {
    vector<int> stack;
    vector<int> visited;
    stack.push_back(1);
    while (stack.size()) {
        visited.push_back(stack.back());
        if (stack.size() == height) {
            int temp = Tree[stack.back()].leftChild;
            Tree[stack.back()].leftChild = Tree[stack.back()].rightChild;
            Tree[stack.back()].rightChild = temp;
            stack.pop_back();
            continue;
        }
        if (find(visited.begin(), visited.end(), Tree[stack.back()].leftChild) == visited.end()
                && Tree[stack.back()].leftChild != -1) {
            stack.push_back(Tree[stack.back()].leftChild);
            continue;
        }
        if (find(visited.begin(), visited.end(), Tree[stack.back()].rightChild) == visited.end()
                && Tree[stack.back()].rightChild != -1) {
            stack.push_back(Tree[stack.back()].rightChild);
            continue;
        }
        stack.pop_back();
    }
}

int main() {
    int N;
    cin >> N;
    Tree.push_back(createNode(1, 1));
    for (int i = 0; i < N; ++i) {
        int left, right;
        cin >> left >> right;
        Tree.push_back(createNode(left, right));
    }
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int K;
        cin >> K;
        for (int j = 1; j * K < N; ++j) {
            swapNodes(j * K);
        }
        inOrderTraversal(1);
        cout << endl;
    }
}
