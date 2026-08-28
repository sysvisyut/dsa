#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <stack>
using namespace std;


class Solution {
public:
    int n;
    string t;
    vector<int> frq;
    char odd = '#';

    string res = "";

    string valid(string &s){
        string temp = s;
        reverse(temp.begin(),temp.end());

        if(odd != '#'){
            s+=odd;
        }
        s+=temp;

        return s;
    }

    bool solve(int i, string &curr, bool isGreater){

        if(curr.size() == n/2){
            string formed = valid(curr);
            if(isGreater && formed > t){
                res = formed;
                return true;
            }
            return false;
        }

        for(char ch='a' ;ch <='z';ch++){
            if(frq[ch-'a'] == 0) continue;

            if(!isGreater && ch < t[i]) continue;

            curr.push_back(ch);
            frq[ch-'a']--;
            
            bool greater = isGreater|| ch>t[i];

            if(solve(i+1,curr,greater)) return true;

            curr.pop_back();
            frq[ch-'a']++;
        }

        return false;
    }
    string lexPalindromicPermutation(string s, string target) {
        
        n = s.size();
        frq.resize(26,0);

        t = target;

        for(char c: s){
            frq[c-'a']++;
        }
        
        int cnt = 0;

        for(int i=0;i<26;i++){
            if(frq[i]&1){
                odd = i+'a';
                cnt++;
            }
            frq[i]/=2;
        }

        if(cnt > 1) return "";

        string curr = "";

        solve(0,curr,false);

        return res;
    }
};