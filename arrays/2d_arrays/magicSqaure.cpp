#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int r= grid.size();
        int c = grid[0].size();
        vector<vector<int>> prefixRow(r,vector<int>(c,0));
        vector<vector<int>> prefixCol(r,vector<int>(c,0));


        for(int i=0;i<r;i++){
            prefixRow[i][0] = grid[i][0];     //row wise prefix sum
            for(int j=1;j<c;j++){
                prefixRow[i][j] = grid[i][j]+prefixRow[i][j-1];
            }
        }
        for(int i=0;i<c;i++){
            prefixCol[0][i] = grid[0][i];
            for(int j=1;j<r;j++){      //column wise prefix sum
                prefixCol[j][i] = grid[j][i]+prefixCol[j-1][i];
            }
        }

        for(int side =min(r,c);side>=1;side--){
            for(int i=0;i+side-1< r;i++){
                for(int j=0;j+side-1< c;j++){
                    int targetSum = prefixRow[i][j+side-1]-(j>0 ?prefixRow[i][j-1] :0);

                    bool allSame = true;

                    for(int row=i+1;row<i+side;row++){
                        int rowSum = prefixRow[row][j+side-1]-(j>0 ?prefixRow[row][j-1] :0);
                        if(rowSum != targetSum){
                            allSame = false;
                            break;
                        }
                    }
                    if(!allSame) continue;

                    for(int col=j;col<j+side;col++){
                        int colSum = prefixCol[i+side-1][col]-(i>0? prefixCol[i-1][col]: 0);
                        if(colSum != targetSum){
                            allSame= false;
                            break;
                        }
                    }
                    if(!allSame){
                        continue;
                    }
                    int diag = 0;
                    int antiDiag=0;
                    for(int k=0;k<side;k++){
                        diag+=grid[i+k][j+k];
                        antiDiag+=grid[i+k][j+side-k-1];

                    }
                    if(diag == targetSum && antiDiag == targetSum){
                        return side;
                    } 
                }
            }
        }
        return 1;
    }
};