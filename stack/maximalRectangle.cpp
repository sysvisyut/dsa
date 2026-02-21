/*Logic: consider each row as height of a histogram and run for loops to store the max height possible for every row and col then apply maxArea in histogram using monotonic stack*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& height){
        stack<int> st;
        int n = height.size();
        int maxArea = 0;

        for(int i=0;i<n;i++){
            while(!st.empty() && height[st.top()] > height[i]){
                int element = st.top();
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1: st.top();
                
                maxArea = max(maxArea, (nse-pse-1)*height[element]);

            }
            st.push(i);
        }
        while(!st.empty()){
            int element = st.top();
            st.pop();
            int nse = n;
            int pse = st.empty()? -1: st.top();

            maxArea = max(maxArea,(nse-pse-1)*height[element]);

        }

        return maxArea;  
    }


    int maximalRectangle(vector<vector<char>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();

        int maxArea = 0;
        vector<int> height(c,0);
      
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(matrix[i][j] == '1'){
                    height[j]++;
                }
                else{
                    height[j] =0;
                }
            }
            int area = largestRectangleArea(height);
            maxArea = max(maxArea,area);
        }

        return maxArea;
    }
};