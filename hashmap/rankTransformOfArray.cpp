#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();

        if(n == 0) return {};

        vector<int> arr1(arr.begin(), arr.end());
        sort(arr1.begin(), arr1.end());
        int rank = 1;

        unordered_map<int,int> mp;
        for(int x: arr1){
            if(!mp.count(x)){
                mp[x] = rank;
                rank++;
            }
        }
 

        for(int i=0;i<n;i++){
            arr[i] = mp[arr[i]];
        }

        return arr;


    }
};