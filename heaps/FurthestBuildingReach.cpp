#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq; //max-heap
        int n = heights.size();
        int i= 0;

        for(;i<n-1;i++){

            if(heights[i+1] <= heights[i]){
                continue;
            }
            int diff = heights[i+1]-heights[i];

            if(bricks >= diff){
                bricks-=diff;
                pq.push(diff); //push the used bricks, so that we have  decide to change it with ladder in future
            }
            else if(ladders > 0){
                if(!pq.empty()){
                    int maxBricks = pq.top();
                    if(maxBricks > diff){
                        bricks+= maxBricks;
                        pq.pop();
                        bricks-=diff;
                        pq.push(diff);
                        
                    }
                          
                }
                ladders--;
            }
            else{
                break;
            }
            
        }
        return i;

    }
};