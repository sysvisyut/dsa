#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <string>
#include <limits>
#include <numeric>
#include <iomanip>

using namespace std;

typedef long long ll;

string helper(string& s) {
    string temp = ""; 

    
    for (int i =0;i<s.size();i++) {
        int c = s[i];
        if (c ==')' && temp.size() >= 3) {
            int n = temp.size();
            if (temp[n - 1] == 'x' &&temp[n - 2] =='x' &&temp[n - 3] == '('){
                temp.pop_back(); 
                temp.pop_back(); 
                temp.pop_back(); 
                temp += "xx";
                continue;
            }
        }
        temp+= c;
    }
        return temp;
}

void solve() {
    string a,b;
    cin>>a>>b;
    if (helper(a) == helper(b)) cout <<"Yes"<<endl;

    else cout<< "No"<< endl;
}

int main() {
    
    int t;
    //int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}