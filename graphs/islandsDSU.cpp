// User function Template for C++
/*logic: create a 2d matrix with all 0's make each operation cell as 1
if that cell is already visited add the curr cnt ans, else inc cnt as the
contribution of that cell and check all the neighbors of this cell if they
if any of the neighbor is 1 then check if their ultimate parents using dsu,
if they have different Uparent then they are not connected so connect them by
using UnionBySize and for everytime u connect two components dec the cnt and add
to ans vector and all operations are completed return the ans vector with all the cnts*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class DisJointSet{
    public:
    vector<int> parent,size;
    DisJointSet(int n){
        parent.resize(n+1);
        size.resize(n+1);
        
        for(int i=0;i<=n;i++){
            parent[i] =i;
            size[i] = 1;
        }
    }
        
        int findUpar(int node){
            if(parent[node] == node) return node;
            
            return parent[node] = findUpar(parent[node]);
        }
        
        void unionBySize(int u,int v){
            int ulp_u = findUpar(u);
            int ulp_v = findUpar(v);
            
            if(ulp_u == ulp_v) return;
            
            if(size[ulp_u] > size[ulp_v]){
                parent[ulp_v] = ulp_u;
                size[ulp_u]+=size[ulp_v];
            }
            else{
                parent[ulp_u] = ulp_v;
                size[ulp_v]+=size[ulp_u];
            }
        }
    
};
class Solution {
  private:
    bool isValid(int adjr, int adjc, int n, int m){
        return adjr<n && adjr>=0 && adjc <m && adjc >=0;
    }
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        DisJointSet ds(n*m);
        vector<vector<int>> mat(n,vector<int>(m,0));
        int cnt=0;
        vector<int> ans;
        for(auto it: operators){
            int row = it[0];
            int col = it[1];
            if(mat[row][col] == 1){
                ans.push_back(cnt);
                continue;
            }
            mat[row][col] = 1;
            cnt++;
            int dr[] = {0,-1,1,0};
            int dc[] = {-1,0,0,+1};
            
            for(int i=0;i<4;i++){
                int adjr = row+dr[i];
                int adjc = col+dc[i];
                
                if(isValid(adjr,adjc,n,m)){
                    if(mat[adjr][adjc] == 1){
                        int adjNode =(adjr*m)+adjc;
                        int node = (row*m)+col;
                        if(ds.findUpar(node) != ds.findUpar(adjNode)){
                            cnt--;
                            ds.unionBySize(node,adjNode);
                        }
                    }
                }
            }
            ans.push_back(cnt);
            
            
            
        }
        return ans;  
    }
};
