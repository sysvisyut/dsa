#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;


class Solution {
public:
    int sq(string s){
        int sum = 0;
        for(char c: s){
            int num = c-'0';
            num*=num;
            sum+=num;
        }

        return sum;
    }
    bool isHappy(int n) {
        unordered_set<string> st;
        string cur = to_string(n);
        while(!st.count(cur)){
            st.insert(cur);
            int sum = sq(cur);
            if(sum == 1) return true;
            cur = to_string(sum);

        }

        return false;
    }
};