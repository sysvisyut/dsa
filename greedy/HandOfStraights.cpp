#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <stack>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();

        if(n%groupSize) return false;

        map<int,int> mp;
        for(int num: hand){
            mp[num]++;
        }

        while(!mp.empty()){
            int curr = mp.begin()->first;

            for(int i=0;i<groupSize;i++){
                if(mp[curr+i] == 0) return false;

                mp[curr+i]--;
                if(mp[curr+i] <1){
                    mp.erase(curr+i);
                }
            }
        }

        return true;
    }
};