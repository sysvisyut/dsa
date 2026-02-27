#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// rowise binary search logic-> TC(n logm)
class Solution {
public:
    int bs(vector<int>& row,vector<vector<int>>& grid){
        int r = row.size()-1;
        int l = 0;

        while(l<=r){
            int mid = (l+r)/2;

            if(row[mid] >= 0){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }

        return row.size()-l;
    }
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();

        int negs = 0;

        for(int i=0;i<n;i++){
            negs+= bs(grid[i],grid);
        }

        return negs;

    }
};

//staircase logic-> TC: O(n+m)

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        int r = 0;           // Start at top row
        int c = cols - 1;    // Start at last column
        int count = 0;
        
        while (r < rows && c >= 0) {
            if (grid[r][c] < 0) {
                // If this is negative, everything below it in this column 
                // is also negative because the columns are sorted.
                count += (rows - r);
                // Move left to see if the previous column has negatives too
                c--;
            } else {
                // If it's positive, move down to find the negative boundary
                r++;
            }
        }
        
        return count;
    }
};