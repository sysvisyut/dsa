#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        
        int n = s.size();

        stack<char> st;
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(s[i] == '('){
                st.push(s[i]);
            }
            if(!st.empty() && st.top() == '(' && s[i] == ')'){
                st.pop();
            }
            else if(s[i] == ')'){
                cnt++;
            }
        }

        return st.size()+cnt;

        
    }
};