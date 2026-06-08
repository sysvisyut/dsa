#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int x,q,v;
    cin>>x>> q;
    
    priority_queue<int> l;
    priority_queue<int, vector<int>, greater<int>> r;
    l.push(x);
    
    while (q--) {
        for (int i = 0; i < 2; ++i) {
            cin >> v;
            if (v <= l.top())l.push(v);

            else r.push(v);
        }
        if (l.size() >r.size() + 1) { 
            r.push(l.top()); 
            l.pop(); 
        }
        if (l.size() <r.size() + 1) { 
            l.push(r.top()); r.pop(); 
        }
        cout << l.top() << "\n";
    }
    return 0;
}