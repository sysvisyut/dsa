#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <stack>
using namespace std;

class BrowserHistory {
public:
    stack<string> f;
    stack<string> b;

    string curr;

    BrowserHistory(string homepage) {
        curr = homepage;
    }
    
    void visit(string url) {
        b.push(curr);
        curr = url;

        while(!f.empty()) f.pop();
    }
    
    string back(int steps) {
        while(steps > 0 && !b.empty()){
            f.push(curr);
            curr = b.top();
            b.pop();
            steps--;
        }
        return curr;
    }
    
    string forward(int steps) {
        
        while(steps > 0 && !f.empty()){
            b.push(curr);
            curr = f.top();
            f.pop();
            steps--;
        }

        return curr;

    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */