#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if(n==0) return {};
        vector<pair<int,int>> v;

        for(int i=0;i<n;i++){
            v.push_back({arr[i],i});
        }

        sort(v.begin(),v.end());

        vector<int> rank(n);

        rank[v[0].second] =1;
        int r =1;

        for(int i=1;i<n;i++){
            if(v[i].first != v[i-1].first){
                r++;
            }
            rank[v[i].second] = r;
        }

        return rank;
    }
};