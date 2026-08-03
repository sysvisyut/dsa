#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int t = tasks.size();
        int n = shifts.size();

        /*both tasks and shifts are in the order of 1e5 so i cant process tasks for each shift, it will give me TLE
        
        i can store the total task time as a prefix array and for each shift i can use binary search to find if the tasks can be completed fully or not , if not i have can to find the
        tasks that can be completed with the curr shift and what should i give extra to the next shift 
        */

        vector<long long> prefix(t+1,0);
    
        for(int i=1;i<=t;i++){
            prefix[i] = tasks[i-1]+prefix[i-1];
        }

        //prefix[t] has the total time to complete all tasks

        vector<int> ans;
        ans.reserve(n);

        long long curr = 0;

        for(int s: shifts){
            
            curr+=s;
            
            if(curr >= prefix[t]){
                curr = 0;
                ans.push_back(0);
            }
            else{
                int left = upper_bound(prefix.begin(),prefix.end(), curr)-prefix.begin();

                ans.push_back(t-left+1);
            }
        }

        return ans;

    }
};