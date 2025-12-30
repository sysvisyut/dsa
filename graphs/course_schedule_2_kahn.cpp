#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inOrder(numCourses,0);
        vector<vector<int>> adj(numCourses);

        for(auto &p: prerequisites){
            adj[p[1]].push_back(p[0]);
        }

        for(auto &p: prerequisites){
            inOrder[p[0]]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(inOrder[i] == 0){
                q.push(i);
            }
        }
        vector<int> ans;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto &n: adj[node]){
                inOrder[n]--;
                if(inOrder[n]==0){
                    q.push(n);
                }
            }
        }
        if(ans.size() != numCourses) return {};

        return ans;
    }
};