#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    vector<string>ans;

    void solve(int index,string digits,string temp,unordered_map<char,string> mp){
        char c = digits[index];
        string str = mp[c];

        if(index >= digits.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<str.size();i++){
            temp.push_back(str[i]);
            solve(index+1,digits,temp,mp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};

        unordered_map<char,string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        solve(0,digits,"",mp);
        return ans;

    }
};