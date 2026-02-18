#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string expand(int left,int right, string s){
        int n = s.size();
        while(left>=0 && right<n && s[left]==s[right]){
            left--;
            right++;
        }
        return s.substr(left+1,right-left-1);
    }
    string longestPalindrome(string s) {
        int n = s.size();
        string maxStr = s.substr(0,1);
        for(int i=0;i<n-1;i++){
            string odd = expand(i,i,s);
            string even = expand(i,i+1,s);

            if(odd.size() > maxStr.size()){
                maxStr = odd;
            }
            if(even.size() > maxStr.size()){
                maxStr = even;
            }

        }

        return maxStr;
    }
};