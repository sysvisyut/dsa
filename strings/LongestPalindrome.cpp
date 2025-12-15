#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        int ans =0;
        bool oddCentre =false;
        for(auto &it : mp){
            if(it.second%2 == 0){
                ans+=it.second;
            }
            else{
                ans+=it.second-1;      //eg: ccc frst take only 2c's
                if(!oddCentre){    //this is for centre of odd >1 and chars with freg == 1;
                    ans+=1;
                    oddCentre = true;   //then check for centre c possibility
                }
            }
        }
        return ans;
    }
};