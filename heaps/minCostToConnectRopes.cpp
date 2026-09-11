#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;


class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        
        int n = arr.size();
    
        
        priority_queue<int,vector<int>,greater<int>> pq(arr.begin(), arr.end());
        
        
        int ans = 0;
        
        while(pq.size() > 1){
            int el1 = pq.top();
            pq.pop();
            int el2 = pq.top();
            pq.pop();
            
            int sum = el1+el2;
            ans+=sum;
            pq.push(sum);
        }
        
        return ans;
    }
};