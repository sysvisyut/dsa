#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int row = strs.size();
        int col = strs[0].size();
        int ans = 0;
        vector<bool>sorted(row-1,false);

        for(int c=0;c <col;c++){
            bool deleted = false;
            for(int r=0;r<row-1;r++){
                if(!sorted[r] && strs[r+1][c] < strs[r][c]){     
                    ans++;
                    deleted = true;
                    break;
                }
            }
            if(deleted) continue;

            for(int i= 0;i<row-1;i++){
               if(!sorted[i] && strs[i][c] < strs[i+1][c]){
                    sorted[i] = true;
               }
            }
        }
        return ans;
    }
};