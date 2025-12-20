#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int c = strs[0].size();
        int r = strs.size();
        int ans = 0;

        for(int i=0;i<c;i++){
            for(int j=1;j<r;j++){
                if(strs[j][i] < strs[j-1][i]){
                    ans++;
                    break;  // no need to check further in this column
                }
            }
        }
        return ans;
    }
};  