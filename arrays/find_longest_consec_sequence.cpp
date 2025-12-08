#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;


class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {

        int n = arr.size();
        unordered_set<int>st(arr.begin(),arr.end());
        int maxi = 1;
        
        for(auto it : st){
            if(!st.count(it-1)){
                int curr = it;
                int len = 1;
                while(st.count(curr+1)){
                    len++;
                    curr++;
                }
                maxi = max(len,maxi);
            }
        }
        return maxi;
        
    }
};