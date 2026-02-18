#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    typedef long long ll;
    vector<ll> fnse(vector<int>& nums){
        int n = nums.size();
        stack<int> st;
        vector<ll> nse(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()] >= nums[i] ){
                st.pop();
            }
            if(st.empty()){
                nse[i] = n;
            }
            else{
                nse[i] = st.top();
            }
            st.push(i);
        }
        return nse;
    }
    vector<ll> fpse(vector<int>& nums){
        int n = nums.size();
        stack<int> st;
        vector<ll> pse(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()] > nums[i] ){
                st.pop();
            }
            if(st.empty()){
                pse[i] = -1;
            }
            else{
                pse[i] = st.top();
            }
            st.push(i);
        }
        return pse;
    }
    vector<ll> fnge(vector<int>& nums){
        int n = nums.size();
        stack<int> st;
        vector<ll> nge(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()] <= nums[i] ){
                st.pop();
            }
            if(st.empty()){
                nge[i] = n;
            }
            else{
                nge[i] = st.top();
            }
            st.push(i);
        }
        return nge;
    }
    vector<ll> fpge(vector<int>& nums){
        int n = nums.size();
        stack<int> st;
        vector<ll> pge(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()] < nums[i] ){
                st.pop();
            }
            if(st.empty()){
                pge[i] = -1;
            }
            else{
                pge[i] = st.top();
            }
            st.push(i);
        }
        return pge;
    }
    long long subArrayRanges(vector<int>& nums) {
        
        int n = nums.size();
        vector<ll> pge = fpge(nums);
        vector<ll> nge = fnge(nums);
        vector<ll> pse = fpse(nums);
        vector<ll> nse = fnse(nums);

        ll minSum =0,maxSum=0;

        for(int i=0;i<n;i++){
            ll l1 = i-pse[i];
            ll r1 = nse[i]-i;
            minSum+=l1*r1*nums[i];
            ll l2 = i-pge[i];
            ll r2 = nge[i]-i;
            maxSum+=l2*r2*nums[i];
        }

        return maxSum - minSum;
    }
};
