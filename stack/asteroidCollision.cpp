#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <stack>
using namespace std;


class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();

        vector<int> st;
        for(int i=0;i<n;i++){
            bool destroyed = false;
            while(!st.empty() && st.back() >0 && asteroids[i]<0){
                if(st.back() > abs(asteroids[i])){
                    destroyed = true;
                    break;
                }
                else if(st.back() < abs(asteroids[i])){
                    st.pop_back();
                }
                else{
                    st.pop_back();
                    destroyed = true;
                    break;
                }
            }
            
            if(!destroyed) st.push_back(asteroids[i]);
            
        }

        return st;

    }
};