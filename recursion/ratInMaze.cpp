#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;


class Solution {
    
  public:
    int dr[4] = {-1,0,+1,0};
    int dc[4] = {0,+1,0,-1};
    vector<string> mazePath;
    bool isValid(int i,int j, int r,int c,vector<vector<int>>& maze){
        return (i>=0 && i<r && j>=0 && j<c && maze[i][j] == 1); 
    }
    void path(int i,int j,int r,int c,vector<vector<int>>& maze,string temp){
        if(i==r-1 && j== c-1){
            mazePath.push_back(temp);
            return;
        }
        int back = maze[i][j];
        maze[i][j] = 2;
        
        for(int k=0;k<4;k++){
            int ni = i+dr[k];
            int nj = j+dc[k];
            if(isValid(ni,nj,r,c,maze)){
                
                temp.push_back("URDL"[k]);
                path(ni,nj,r,c,maze,temp);
                temp.pop_back();
            }
        }
            

        maze[i][j] = back;
            
        
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        int r= maze.size();
        int c = maze[0].size();
        
        string temp = "";
        path(0,0,r,c,maze,"");
        
        sort(mazePath.begin(),mazePath.end());
        return mazePath;
    }
};