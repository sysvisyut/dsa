#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
   
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> glass;

        for(int i=1;i<=100;i++){
            vector<double> row(i,0.0);
            glass.push_back(row);
        }

        glass[0][0] = poured;

        for(int i=0;i<query_row;i++){
            for(int j=0;j<=i;j++){
                if(glass[i][j] > 1.0){
                    double extra = glass[i][j] - 1;
                    double left = extra/2;
                    double right = extra/2;

                    glass[i+1][j] += left;
                    glass[i+1][j+1] += right;
                    glass[i][j] = 1.0;

                }
            }
        }

        return min(1.0,glass[query_row][query_glass]);


        
    }
};