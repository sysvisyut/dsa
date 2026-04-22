#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int check(string& s, string& d){
        int n = s.size();
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(s[i] != d[i]) cnt++;

            if(cnt >2) break;
        }

        return cnt;
    }
    vector<string> twoEditWords(vector<string>& que, vector<string>& dict) {
        
        vector<string> ans;
        for(string s: que){
            for(string d: dict){
                if(check(s,d) <= 2){
                    ans.push_back(s);
                    break;
                }
            }
        }

        return ans;

    }
};