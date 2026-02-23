#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;


class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int res = 1<<k;
        int n = s.size();
        unordered_set<string> st;
        for(int i=0;i<=n-k;i++){
            string temp = s.substr(i,k);
            if(!st.count(temp)){
                st.insert(temp);
                res--;
            }
            if(res == 0){
                return true;
            }
        }
        return false;
    }
};