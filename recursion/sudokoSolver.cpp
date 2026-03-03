#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char c){
        for(int i=0;i<9;i++){
            if(board[row][i] == c) return false;

            if(board[i][col] == c) return false;

            int boxR = (row/3)*3;
            int boxC = (col/3)*3;

            for(int k=0;k<3;k++){
                for(int l=0;l<3;l++){
                    if(board[boxR+k][boxC+l] == c) return false;
                }
            }
        }
        return true;
    }

    bool solve(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] == '.'){
                    for(char c = '1';c <='9';c++){
                        if(isValid(board,i,j,c)){
                            board[i][j] = c;
                            if(solve(board)) return true;

                            board[i][j] = '.';
                        } 
                    }
                    return false;
                }
            }
        }

        return true;

    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};