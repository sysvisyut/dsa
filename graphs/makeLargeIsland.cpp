#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <set>
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
    bool isValid(int adjr,int adjc, int n){
        return adjr<n && adjr>=0 && adjc < n && adjc >= 0;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
       
        DisJointSet ds(n*n);
        //step 1: make all the 1s as connected components
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col] == 1){
                    int dr[] = {0,-1,+1,0};
                    int dc[] = {-1,0,0,+1};
                    for(int i=0;i<4;i++){
                        int adjr = row+dr[i];
                        int adjc = col+dc[i];

                        if(isValid(adjr,adjc,n)){
                            if(grid[adjr][adjc] == 1){
                                int node = (row*n)+col;
                                int adjNode = (adjr*n)+adjc;

                                ds.unionBySize(node,adjNode);
                            }
                        }
                    }
                }
            }
        }
       //step 2: find all zeros and connect cnt them with all the alr existing components and store the max cnt

        int max_size = 0;
       for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col] == 0){
                    int dr[] = {-1,0,1,0};
                    int dc[] = {0,1,0,-1};

                    set<int> components; // stores only unique compoenets to avoid repeated values
                    for(int i=0;i<4;i++){
                        int adjr = row+dr[i];
                        int adjc = col+dc[i];
                        if(isValid(adjr,adjc,n)){
                            if(grid[adjr][adjc] == 1){
                                int adjNode  = (adjr*n)+adjc;
                                components.insert(ds.findUpar(adjNode));
                            }
                        }
                    }
                    int size_total =0;
                    for(auto it: components){
                        size_total+= ds.size[it];
                    }
                    max_size = max(size_total+1,max_size);
                }
            }
        }

        for(int cellNo = 0;cellNo < n*n; cellNo++){
            max_size = max(max_size,ds.size[ds.findUpar(cellNo)]); //case where all values in grid is 1
        }

        return max_size;
    }
};