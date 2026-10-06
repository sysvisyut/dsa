#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();

        stack<int> st1,st2;

        for(int i=0;i<n;i++){
            if(s[i] == '['){
                st1.push(i);
            }
            else{
                if(!st1.empty()){
                    st1.pop();
                }
                else{
                    st2.push(i);
                }
            }
        }

        return (st2.size()+1)/2;

    }
};