#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

/*question: Given a binary string s, return the number of non-empty substrings that have the same number of 0's and 1's, and all the 0's and all the 1's in these substrings are grouped consecutively.

Substrings that occur multiple times are counted the number of times they occur.

 

Example 1:

Input: s = "00110011"
Output: 6
Explanation: There are 6 substrings that have equal number of consecutive 1's and 0's: "0011", "01", "1100", "10", "0011", and "01".
Notice that some of these substrings repeat and are counted the number of times they occur.
Also, "00110011" is not a valid substring because all the 0's (and 1's) are not grouped together.
Example 2:

Input: s = "10101"
Output: 4
Explanation: There are 4 substrings: "10", "01", "10", "01" that have equal number of consecutive 1's and 0's.*/

/*logic: to find the no of substrings with same no of consecutive ones and zeros,for 
each sequence of ones or zeros count them and store it in a vector and total number of 
substrings that could be formed is min(i,i+1)*/
class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        vector<int> ans;
        int zcnt =0;
        int ocnt =0;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                if(ocnt > 0){
                    ans.push_back(ocnt);
                    ocnt =0;
                }
                zcnt++;
            }
            else{
                if(zcnt>0){
                    ans.push_back(zcnt);
                    zcnt =0;
                }
                ocnt++;
            }
        }
        if(zcnt > 0){
            ans.push_back(zcnt);
        }
        if(ocnt > 0){
            ans.push_back(ocnt);
        }

        int ansCnt=0;

        for(int i=0;i<ans.size()-1;i++){
            ansCnt+= min(ans[i],ans[i+1]);
        }

        return ansCnt;

    }
};