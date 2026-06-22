#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;

        for(char c: s) mp1[c]++;
        for(char c: target) mp2[c]++;
        
        int ans = INT_MAX;

        for(auto& [c,frq] : mp2){
            ans = min(ans, mp1[c]/frq);
        }
        return ans;
    }
};