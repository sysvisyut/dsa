#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        st.push(s[0]);

        for(int i=1;i<s.size();i++){
            char c = s[i];

            if(st.size() >=1 && c == st.top()){
                st.pop();
            }
            else{
                st.push(c);
            }
        }
        string res = "";

        while(!st.empty()){
            res+=st.top();
            st.pop();
        }

        reverse(res.begin(),res.end());

        return res;
    }
};