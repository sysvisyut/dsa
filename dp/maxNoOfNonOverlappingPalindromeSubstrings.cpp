
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    int n;
    vector<vector<bool>> check;

    int maxPalindromes(string s, int k) {

        n = s.size();
        check.resize(n,vector<bool>(n,false));

        for(int i=0;i<n;i++){
            check[i][i] = true; 
        }

        for(int i=0;i<n-1;i++){
            check[i][i+1] = (s[i] == s[i+1]);
        }

        for(int len = 3;len <=n ;len++){
            for(int l=0;l+len-1 < n;l++){
                int r = l+len-1;

                if(s[l] == s[r] && check[l+1][r-1]){
                    check[l][r] = true;
                }
            }
        }

        int cnt = 0;
        int i = 0;
        while(i < n){
            
            if(i+k-1 < n && check[i][i+k-1]){
                cnt++;
                i+=k;
            }
            else if(i+k < n && check[i][i+k]){
                cnt++;
                i+= k+1;
            }
            else{
                i++;
            }
        }

        return cnt;
        
    }
};