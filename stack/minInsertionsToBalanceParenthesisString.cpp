#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        
        int n = s.size();
        
        int cnt = 0;
        int res= 0;
        int i=0;

        while(i< n){
            
            if(s[i] == '('){ //cnt keep tracks of the ( cnt
                cnt++;
                i++;
            }
            else{
                if(cnt > 0){ // the ) has a open bracket before it
                    cnt--;
                }
                else{
                    res++; // there was no ( so add one through insertion
                }

                if(i+1 < n && s[i+1] == ')'){
                    i+=2;  // the ( has 2 close brackets 
                }else{
                    res+=1; // need one more ) to balance 
                    i++;
                }
            }
        }

        return res+(2*cnt);  // cnt has the open brackets that wasn't balanced yet
    }
};