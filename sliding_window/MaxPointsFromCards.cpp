#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

        int n = cardPoints.size();
        int frontSum = 0;

        for(int i=0;i<k;i++){
            frontSum+= cardPoints[i];
        }
        int maxPoints = frontSum;

        for(int i=0;i<k;i++){
            frontSum-=cardPoints[k-i-1];
            
            frontSum+=cardPoints[n-i-1];
            if(frontSum > maxPoints){
                maxPoints = max(maxPoints,frontSum);
            }
        }

        return maxPoints;
    }
};