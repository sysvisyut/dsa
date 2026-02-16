#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <stack>
using namespace std;
/*start traversing from the back of the array and store the elements into the stack if the 
stack is empty that means either its the last element or the curr element doesnt have any nge
 to its right, so store -1, else pop the stack will the top of the stack becomes greater than 
 the current element and store it*/
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int,int> nge;
        int n1 = nums2.size();
        for(int i=n1-1;i>=0;i--){

            while(!st.empty() && st.top() <= nums2[i]){
                st.pop();
            }
            if(st.empty()){
                nge[nums2[i]] = -1;
            }
            else{
                nge[nums2[i]] = st.top();
            }
            st.push(nums2[i]);
        }
        vector<int> ans;

        for(int i=0;i<nums1.size();i++){
            ans.push_back(nge[nums1[i]]);
        }

        return ans;
    }
};