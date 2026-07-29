#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        
        int n = s.size();
        int zcnt = count(s.begin(),s.end(),'0');

        vector<int> zidx1;

        for(int i=0;i<n;i++){
            if(s[i] == '0'){
                zidx1.push_back(i);
            }
        }

        vector<bool> ans;

        for(string t: strs){

            int q = count(t.begin(),t.end(),'?');
            int z = count(t.begin(),t.end(),'0');

            if(z > zcnt || q+z < zcnt){
                ans.push_back(false);
                continue;
            }

            int need = zcnt-z;

            for(char &c: t){
                if(c == '?'){
                    if(need){
                        c='0';
                        need--;
                    }
                    else{
                        c='1';
                    }
                }
            }

            vector<int> zidx2;

            for(int i=0;i<n;i++){
                if(t[i] == '0'){
                    zidx2.push_back(i);
                }
            }

            bool ok = true;

            for(int i=0;i<zcnt;i++){
                if(zidx1[i] < zidx2[i]){
                    ok = false;
                }
            }
            ans.push_back(ok);
        }
        return ans;

    }
};