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
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.rbegin(),prices.rend());
        sort(discounts.rbegin(),discounts.rend());

        int n = discounts.size();
        int m = prices.size();

        double final_price = 0;
        int i=0;
        for(;i<min(n,m);i++){
            final_price+= prices[i]*(100.0-discounts[i])/100.0;
        }

        while(i<m){
            final_price+=prices[i];
            i++;
        }

        return final_price;


    }
};