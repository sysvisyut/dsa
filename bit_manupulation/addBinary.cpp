#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size()-1;
        int j = b.size()-1;
        int carry =0;
        int sum =0;
        string res = "";

        while(i>=0 || j>= 0){
            sum = carry;

            if(i>=0){
                sum+= a[i]-'0';
                i--;
            }
            if(j>=0){
                sum+= b[j]-'0';
                j--;
            }
            res+=(sum%2)+'0';

            carry = sum/2;

        }
        if(carry){
            res+='1';
        }

        reverse(res.begin(),res.end());

        return res;

    }
};