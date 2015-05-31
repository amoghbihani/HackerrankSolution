#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct StationFare {
    int id;
    int fare;
};

struct Node {
    int id;
    vector<StationFare> adjacentNodes;
};

typedef vector<int> Path;
typedef vector<Path> AllPaths;

StationFare createStationFare(int id, int fare) {
    StationFare temp;
    temp.id = id;
    temp.fare = fare;
    return temp;
}

Node createEmptyNode(int id) {
    Node temp;
    temp.id = id;
    return temp;
}

vector<Node> Tree;
vector<bool> VisitedNode;

void reset() {
    for (int i = 0; i < VisitedNode.size(); ++i) {
        VisitedNode[i] = false;
    }
}

AllPaths findAllPaths(int start, int end) {
    reset();
    AllPaths allPaths;
    vector<int> stack;
    vector<int> secondLastNode;
    stack.push_back(start);
    VisitedNode[start] = true;
    while (stack.size()) {
        int nodeId = stack.back();
        if (nodeId == end) {
            allPaths.push_back(stack);
            for (int j = 0; j < stack.size(); ++j) {
                cout << stack[j] << " ";
            }
            cout << endl;
            VisitedNode[end] = true;
            stack.pop_back();
            secondLastNode.push_back(stack.back());
            continue;
        }
        for (int i = 0; i < Tree[nodeId].adjacentNodes.size(); ++i) {
            int id = Tree[nodeId].adjacentNodes[i].id;
            if (VisitedNode[id] && id != end) {
                continue;
            }
            if (id == end
                && find(secondLastNode.begin(), secondLastNode.end(), nodeId)
                    != secondLastNode.end()) {
                continue;
            }
            stack.push_back(id);
            VisitedNode[id] = true;
            break;
        }
        if (stack.back() == nodeId) {
            stack.pop_back();
            // for (int i = 0; i < Tree[nodeId].adjacentNodes.size(); ++i) {
            //     int tempNodeId = Tree[nodeId].adjacentNodes[i].id;
            //     if (find(stack.begin(), stack.end(), tempNodeId) != stack.end()) {
            //         cout << "found in stack" << nodeId << " " << tempNodeId << endl;
            //         continue;
            //     }
            //     VisitedNode[tempNodeId] = false;
            // }
        }
    }
    return allPaths;
}

int main () {
    int N, E;
    cin >> N >> E;
    for (int i = 0; i <= N; ++i) {
        Tree.push_back(createEmptyNode(i));
        VisitedNode.push_back(false);
    }
    for (int i = 0; i < E; ++i) {
        int n1, n2, fare;
        cin >> n1 >> n2 >> fare;
        Tree[n1].adjacentNodes.push_back(createStationFare(n2, fare));
        Tree[n2].adjacentNodes.push_back(createStationFare(n1, fare));
    }
    int minFare = -1;
    AllPaths allPaths = findAllPaths(1, N);
    for (int i = 0; i < allPaths.size(); ++i) {
        int cumulativeFare = 0;
        // cout << "path: " << i << endl;
        for (int j = 0; j < allPaths[i].size() - 1; ++j) {
            vector<StationFare>::iterator it = Tree[allPaths[i][j]].adjacentNodes.begin();
            int fare = 0;
            for (; it != Tree[allPaths[i][j]].adjacentNodes.end(); ++it) {
                if (it->id == allPaths[i][j + 1]) {
                    fare = it->fare - cumulativeFare;
                    // cout << fare << endl;
                }
            }
            if (fare < 0) {
                fare = 0;
            }
            cumulativeFare += fare;
        }
        if (cumulativeFare < minFare || minFare < 0) {
            minFare = cumulativeFare;
        }
    }
    cout << minFare << endl;
}
