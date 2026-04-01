#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> order(n);
        iota(order.begin(),order.end(),0); //create a sequence from 0 till order size(indexes)
        // then sort the indexes based on the position
        sort(order.begin(),order.end(), [&](int a,int b){
            return positions[a] < positions[b];
        });

        stack<int> st;
        vector<bool> dead(n, false);

        for(int i: order){
            if(directions[i] == 'R'){
                st.push(i);
            }
            else{ // is the curr rbt direction is 'L'
                while(!st.empty() && directions[st.top()] == 'R'){ // collision condition
                    int top = st.top();
                    if(healths[top] > healths[i]){
                        healths[top]--;
                        dead[i] = true;
                        break;
                    }
                    else if(healths[top] < healths[i]){
                        healths[i]--;
                        dead[top] = true;
                        st.pop();
                    }
                    else{
                        dead[i] = true;
                        dead[top] = true;
                        st.pop();
                        break;
                    }
                }
                if(!dead[i]) st.push(i);
            }
        }

        vector<int> ans;
        for(int i=0;i<n;i++){
            if(!dead[i]){
                ans.push_back(healths[i]);
            }
        }

        return ans;
    }
};