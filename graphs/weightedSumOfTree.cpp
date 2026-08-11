#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
typedef long long ll;

    int dfs(int node, vector<vector<ll>>& adj){
        int h = 0;

        for(int nei: adj[node]){
            h = max(h, dfs(nei,adj)+1);
        }

        return h;
    }

    long long weightedSum(vector<int>& parent, vector<int>& nums) {

        int n = nums.size();
        
        vector<vector<ll>> adj(n);

        for(int i=0;i<n;i++){
            if(parent[i] == -1) continue;

            adj[parent[i]].push_back(i);
        }

        ll ans = 0;

        int h = dfs(0,adj)+1;
        int d = 0;

        //cout<<h<<endl;

        queue<int> q;

        q.push(0);

        while(!q.empty()){
            int sz = q.size();
            d++;

            for(int i=0;i<sz;i++){
                int node = q.front();
                ll val = nums[node];
                //cout<<val<<" ";
                ans+= val*(h-d+1);
                //cout<<ans<<endl;
                q.pop();

                for(int nei: adj[node]){
                    q.push(nei);
                }
            }
        }

        return ans;
    }
};