#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <sstream>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;

        stringstream ss(s);
        string word;

        while(ss >> word){
            words.push_back(word);
        }

        if(words.size() != pattern.size()) return false;

        unordered_map<char,string> mp1;
        unordered_map<string,char> mp2;

        
        for(int i=0;i< words.size();i++){
            
            char c = pattern[i];
            string s = words[i];

            if(mp1.count(c) && mp1[c] != s) return false;

            if(mp2.count(s) && mp2[s] != c) return false;

            mp1[c] = s;
            mp2[s] = c;
        }
        return true;
        
    }
};