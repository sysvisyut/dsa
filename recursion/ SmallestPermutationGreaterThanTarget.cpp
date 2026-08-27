#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> frq;
    string T;
    string res = "";

    bool solve(int i, string &curr, bool isGreater){

        if(i == T.size()){
            if(isGreater){
                res = curr;
                return true;
            }
            return false;
        }

        for(char ch = 'a';ch <= 'z'; ch++){
            if(frq[ch-'a']==0) continue;

            if(isGreater == false && ch < T[i]) continue;

            curr.push_back(ch);
            frq[ch-'a']--;
            
            bool CurrGreaterState = ch > T[i] || isGreater;
            if(solve(i+1,curr,CurrGreaterState)){
                return true;
            }
            curr.pop_back();
            frq[ch-'a']++;
        }

        return false;
    }
    string lexGreaterPermutation(string s, string target) {
        
        int n = s.size();
        T = target;

        frq.resize(26,0);

        for(char c: s){
            frq[c-'a']++;
        }

        string curr = "";
        solve(0,curr,false);

        return res;

    }
};