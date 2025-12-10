#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int m = 1e9+7;
        int n = complexity.size();
        for(int i =1;i<n;i++){
            if(complexity[0] >= complexity[i]) return 0;    //if first element is not minimum then some computers cannot be unlocked
        }   
        long long ans = 1;
        for(int i=1;i<n;i++){
            ans = (ans*i)%m;       //if frst one is the smallest and unique, the all permutations are possible to unlock -> (N-1)!
        }

        return (int)ans;
    }
};