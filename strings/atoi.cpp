#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.size();
        long long ans = 0;

        if(s.empty()) return 0;

        while(i<n && s[i] == ' '){
            i++;
        }
        s = s.substr(i);
        n = s.size();

        int sign = +1;

        if(s[0] == '-') sign = -1;

        int maxi = INT_MAX, mini = INT_MIN;
        i = (s[0]=='+' || s[0]== '-') ? 1:0;

        while(i<n){
            if(s[i]== ' ' || !isdigit(s[i])) break;

            ans = ans*10 + s[i]-'0';

            if(sign == -1 && -ans < mini) return mini;
            if(sign == 1 && ans> maxi) return maxi;
            i++;
        }

        return (int)(sign*ans);
        
    }
};