#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;


class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        int neg =0;
        int mini = INT_MAX;
        long long sum =0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(matrix[i][j] <0){
                    neg++;
                }
                sum+=abs(matrix[i][j]);
                mini = min(abs(matrix[i][j]),mini);
            }
        }
        
        if(neg%2 !=0){
            return sum-(2*mini);//if odd we try to make the least number in the grid to be neg
        }
        return sum; //if the neg are even everything can be made positive
    }
};