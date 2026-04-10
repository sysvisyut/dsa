#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:

    bool isPalindrome(int st, int end, string& s){
        while (st < end){
            if(s[st] == s[end]){
                st++;
                end--;
            }
            else return false;
        }
        return true;
    }

    void helper(int ind,string&s, vector<string>& curr,vector<vector<string>>& ans){
        if(ind == s.size()){
            ans.push_back(curr);
            return;
        }

        for(int i=ind;i<s.size();i++){
            if(isPalindrome(ind,i,s)){
                curr.push_back(s.substr(ind,i-ind+1));// start exploring the same fn from the next index
                helper(i+1,s,curr,ans);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        helper(0,s,curr,ans);

        return ans;

    }
};