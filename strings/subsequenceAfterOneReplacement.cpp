#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();

        if(n > m) return false;
        if(n ==0) return true;

        vector<int> left(n,-1), right(n,-1);

        int j =0;

        for(int i=0;i<n;i++){
            while(j <m && t[j]!= s[i]){
                j++;
            }
            if(j == m) break;

            left[i] = j; //index where prefix i matched in t
            j++;
        }
        if(left[n-1] != -1){
            return true; // all chars of S already matched with T, already a subsequence
        }

        j = m-1; //start from behind to check suffix matching

        for(int i=n-1;i>=0;i--){
            while(j >=0 && t[j] != s[i]){
                j--;
            }
            if(j <0) break;
            right[i] = j;
            j--;
        }

        for(int i=0;i<n;i++){
            if((i == 0 || left[i-1] != -1)&&(i==n-1 ||right[i+1] != -1)){
                int L = (i==0) ? -1 : left[i-1];
                int R = (i==n-1)? m :right[i+1];


                if(L+1 < R) return true;
            }
        }

        return false;

    }
};