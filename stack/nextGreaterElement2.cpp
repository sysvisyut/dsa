#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <stack>
using namespace std;

/* same logic as nge1 but instead starting with empty stack push all the elements in the stack
ans perform nge1*/ 

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;

        for(int i=n-1;i>=0;i--){
            st.push(nums[i]);
        }
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top() <= nums[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i] = -1;
            }
            else{
                ans[i] = st.top();
            }
            st.push(nums[i]);
        }

        return ans;
    }
};