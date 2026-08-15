#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <sstream>

using namespace std;

class Solution {
public:
    bool check(string &s){
        int l = 0;
        int r = s.size()-1;

        while(l < r){
            if(s[l] != s[r]) return false;
            l++;r--;
        }
        return true;
    }
    
    int fn(string s){
        int l =0; int r=s.size()-1;
        int req = 0;

        while(l < r){
            if(s[l] != s[r]){
                int diff = abs(s[l]-s[r]);
                req+= min(diff,26-diff);
                l++;r--;
            }
            else{
                l++;r--;
            }
        }

        return req;
        
    }
    int minOperations(string s) {
       
        int n = s.size();

        if(check(s)){
            return 0;
        }
          
        int ans = INT_MAX;
        string f = s+s;
      
       
        for(int i=0;i<n;i++){
            
            string curr = f.substr(i,n);
            ans = min(ans, i+fn(curr));
            
        }

        return ans;
    }
};