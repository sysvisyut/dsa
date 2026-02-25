#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <stack>
using namespace std;


class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        vector<int> mp(26,0);

        for(char ch: tasks){
            mp[ch-'A']++;
        }
        sort(mp.rbegin(),mp.rend());

        int maxfrq = mp[0];
        int gaps = maxfrq-1;
        int slots = gaps*n;

        for(int i=1;i<mp.size();i++){
            slots-= min(mp[i],gaps);
        }

        if(slots > 0){
            return tasks.size()+slots;
        }

        return tasks.size();
    }
};