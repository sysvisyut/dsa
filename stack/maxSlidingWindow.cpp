#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <stack>
using namespace std;

/*logic: -> check if the front index of queue of out of curr window size by i-k
            if yes pop_front()

        ->check if the last element of the queue is smaller than the curr element if yes pop_back, i.e queue stores element in decreasing order
        
        -> after this for each iteration check if the curr window size is valid if yes push it into answer vector*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        deque<int> dq;
        vector<int> ans;

        for(int i =0;i<n;i++){
            if(!dq.empty() && dq.front() <= i-k){
                dq.pop_front();
            }
            while(!dq.empty() && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);

            if(i >= k-1){
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};