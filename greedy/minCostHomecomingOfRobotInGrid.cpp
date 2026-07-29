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
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {

        int totalCost=0;
        int x = startPos[0];
        int y = startPos[1];
        int fx = homePos[0];
        int fy = homePos[1];

        int r = rowCosts.size();
        int c = colCosts.size();

        while(x!=fx || y!=fy){

            if(x < fx && x+1 < r){
                x++;
                //cout<<rowCosts[x]<<" ";
                totalCost+= rowCosts[x];
            }
            else if(x > fx && x-1>=0){
                x--;
                //cout<<rowCosts[x]<<" ";
                totalCost+= rowCosts[x];
            }
            if(y < fy && y+1 < c){
                y++;
                //cout<<colCosts[y]<<" ";
                totalCost+= colCosts[y];
            }
            else if(y > fy && y-1>=0){
                y--;
                //cout<<colCosts[y]<<" ";
                totalCost+= colCosts[y];
            }
            
        }

        return totalCost;
        
    }
};