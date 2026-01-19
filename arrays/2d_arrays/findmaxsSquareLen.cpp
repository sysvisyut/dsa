#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int cal_sum(int row,int col, int r2,int c2,vector<vector<int>>& prefix){
        int sum = prefix[r2][c2];
        if(row >0){
            sum= sum- prefix[row-1][c2];
        }
        if(col >0){
            sum = sum -prefix[r2][col-1];
        }
        if(row >0 && col >0){
            sum= sum+prefix[row-1][col-1];
        } // cal sum of 2d matrix in 2d matrix
        
        return sum;
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int r = mat.size();
        int c = mat[0].size();

        vector<vector<int>> prefix(r,vector<int>(c,0));

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                prefix[i][j] = (i >0 ? prefix[i-1][j] :0)+(j >0 ? prefix[i][j-1] : 0)-
                ((i>0 && j>0) ? prefix[i-1][j-1] : 0)+mat[i][j]; // prefix matrix creation
            }
        }
        int best_sq = 0;
        int curr = 0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                for(int k=best_sq;k<min(c-j,r-i);k++){
                    int r2 = i+k;
                    int c2 = j+k;
                    if(cal_sum(i,j,r2,c2,prefix) <= threshold){
                        curr = k+1;
                        best_sq = max(best_sq,curr);
                    }else{
                        break;
                    }
                }
            }
        }
        return best_sq;
    }
};