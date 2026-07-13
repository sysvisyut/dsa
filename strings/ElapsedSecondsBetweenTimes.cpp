#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <sstream>

using namespace std;

class Solution {
public:

    int helper(string t){
        stringstream ss(t);
        string sep;

        vector<int> time;
        
        while(getline(ss,sep,':')){
            time.push_back(stoi(sep));
        }
        return time[0]*3600 + time[1]*60 +time[2];
    }
    int secondsBetweenTimes(string startTime, string endTime) {

        return helper(endTime)- helper(startTime);
        
    }
};