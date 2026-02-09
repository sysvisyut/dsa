#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string t = a;
        int ans = 1;

        while(a.size() < b.size()){//make a atleast the size of b
            a+=t;
            ans++;
        }
        if(a.find(b)!= string::npos){ //check if b is a substring of a
            return ans;
        }

        a+=t;       //if not add a once more
        ans++;
        if(a.find(b) != string::npos) return ans;

        return -1;

        
    }
};