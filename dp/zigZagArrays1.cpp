#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;


class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        int m = r-l+1; // l to r, is same as 0 to r-l+1, we only need the cnt to l,r doesnt matter

        int mod = 1e9+7;
        
        /*dp state reprents 
        up[][] -> no of arrays of len n where */
        vector<vector<int>>up (n+1, vector<int>(m,0));
        vector<vector<int>> down(n+1,vector<int>(m,0));


        // base case when we have only 2 numbers it either x>y or y>x are only valid
        for(int x=0;x<m;x++){
            for(int y=0;y<m;y++){
                if(x == y) continue;

                if(x < y){
                    up[2][y] = (up[2][y]+1)%mod;
                }
                else{
                    down[2][y] = (down[2][y]+1)%mod;
                }
            }
        }
        // transition in happens for 3-n

        for(int i=3;i<=n;i++){
            vector<int> prefUp(m+1,0), prefDown(m+1,0);

            for(int j=0;j<m;j++){
                prefUp[j+1] = (prefUp[j]+ up[i-1][j])%mod;
                prefDown[j+1] = (prefDown[j]+ down[i-1][j])%mod;
            }

            for(int y=0;y<m;y++){
                //up[i][y] = sum of all down[i-1][x] where x < y
                up[i][y] = prefDown[y];


                //down[i][y] = sum of all up[i-1][x] where x > y
                down[i][y] = ((prefUp[m]-prefUp[y+1])%mod +mod)%mod;
            }
        }
        
        long long ans = 0;
        
        for(int y=0;y<m;y++){
            ans = (ans + up[n][y]+down[n][y])%mod;
        }

        return ans;

    }
};