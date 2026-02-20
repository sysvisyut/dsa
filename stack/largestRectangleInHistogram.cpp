#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <stack>
using namespace std;


class Solution {
public:
    vector<int> fnse(vector<int>& heights){
        int n = heights.size();
        stack<int> st;
        vector<int> nse(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()] > heights[i]){
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

    vector<int> fpse(vector<int>& heights){
        int n = heights.size();
        stack<int> st;
        vector<int> pse(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
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
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> size;

        vector<int> nse = fnse(heights);
        vector<int> pse = fpse(heights);

        int maxArea = INT_MIN;
        
        for(int i=0;i<n;i++){
            maxArea = max(maxArea,(nse[i]-pse[i]-1)*heights[i]);
        }

        return maxArea;

    }
};