#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isMagic(vector<vector<int>>& g, int r, int c) {
        // 1. Center must be 5
        if (g[r+1][c+1] != 5) return false;

        // 2. Check all numbers are 1–9 and unique
        vector<int> freq(10, 0);
        for (int i = r; i < r + 3; i++) {
            for (int j = c; j < c + 3; j++) {
                int x = g[i][j];
                if (x < 1 || x > 9 || freq[x]++) 
                    return false;
            }
        }

        // 3. Check sums
        return
            g[r][c] + g[r][c+1] + g[r][c+2] == 15 &&
            g[r+1][c] + g[r+1][c+1] + g[r+1][c+2] == 15 &&
            g[r+2][c] + g[r+2][c+1] + g[r+2][c+2] == 15 &&

            g[r][c] + g[r+1][c] + g[r+2][c] == 15 &&
            g[r][c+1] + g[r+1][c+1] + g[r+2][c+1] == 15 &&
            g[r][c+2] + g[r+1][c+2] + g[r+2][c+2] == 15 &&

            g[r][c] + g[r+1][c+1] + g[r+2][c+2] == 15 &&
            g[r][c+2] + g[r+1][c+1] + g[r+2][c] == 15;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;

        for (int i = 0; i + 2 < rows; i++) {
            for (int j = 0; j + 2 < cols; j++) {
                if (isMagic(grid, i, j))
                    count++;
            }
        }
        return count;
 
    }
};