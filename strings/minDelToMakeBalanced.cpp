#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();

        int acnt =0;
        int bcnt=0;

        for(int i=0;i<n;i++){
            if(s[i]=='a') acnt++;
        }

        int min_del =INT_MAX;

        for(int i=0;i<n;i++){
            if(s[i]=='a'){
                acnt--;
                min_del = min(min_del,acnt+bcnt);
            }
            else{
                min_del = min(min_del,acnt+bcnt);
                bcnt++;
            }
        }

        return min_del;
    }
};