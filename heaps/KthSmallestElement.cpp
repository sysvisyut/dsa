#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;



class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        priority_queue<int> pq; //max_heap
        
        for(int i=0;i<arr.size();i++){
            pq.push(arr[i]);
            
            if(pq.size() > k){
                pq.pop();
            }
        }
        
        return pq.top();
        
    }
};