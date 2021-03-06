#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int lonelyinteger(vector<int> a) {
    int last = a.back();
    a.pop_back();
    vector<int>::iterator it = a.begin();
    for (; *it != last && it != a.end(); ++it); // intentional
    if (it == a.end()) {
        return last;
    } else {
        a.erase(it);
    }
    return lonelyinteger(a);
}
int main() {
    int res;
    
    int _a_size;
    cin >> _a_size;
    vector<int> _a;
    int _a_item;
    for(int _a_i=0; _a_i < _a_size; ++_a_i) {
        cin >> _a_item;
        _a.push_back(_a_item);
    }
    
    res = lonelyinteger(_a);
    cout << res;
    
    return 0;
}
