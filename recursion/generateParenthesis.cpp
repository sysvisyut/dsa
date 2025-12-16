#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    vector<string>temp;
    bool isValid(string curr){
        int n = curr.size();
        int cnt =0;             // TC: O(2^(2*n) * n), n because isValid fn checks for every curr
        for(int i=0;i<n;i++){
            if(curr[i] == '(') cnt++;
            else cnt--;

            if(cnt <0) return false;
        }
        return cnt==0;
    }
    void helper(string curr,int n){
        if(curr.size()==(n*2)){
            if(isValid(curr)){
                temp.push_back(curr);
            }
            return;
        }
        curr.push_back('(');
        helper(curr,n);
        curr.pop_back();
        curr.push_back(')');
        helper(curr,n);
        curr.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        helper("",n);
        return temp;
    }
};