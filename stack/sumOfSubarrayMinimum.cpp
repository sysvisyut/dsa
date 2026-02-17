#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <stack>
using namespace std;




class Solution {
public:
    
    int MOD = 1e9+7;
    vector<int> fpse(vector<int>& arr){
        int n = arr.size();
        stack<int> st;
        vector<int> arr1(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            if(st.empty()){
                arr1[i] = -1;
            }
            else{
                arr1[i] = st.top();
            }
            st.push(i);
        }
        return arr1;
    }
    vector<int> fnse(vector<int>& arr){
        int n = arr.size();
        stack<int> st;
        vector<int> arr2(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(st.empty()){
                arr2[i] = n;
            }
            else{
                arr2[i] = st.top();
            }
            st.push(i);
        }
        return arr2;
    }
    int sumSubarrayMins(vector<int>& arr){
        int n = arr.size();
        int sum =0;
        vector<int> nse = fnse(arr);
        vector<int> pse = fpse(arr);

        for(int i=0;i<n;i++){
            int l = i-pse[i];
            int r = nse[i]-i;

            sum = (sum+(1LL*l*r*arr[i])%MOD)%MOD;
        }


        return sum;

    }
};