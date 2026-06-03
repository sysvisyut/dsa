#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <string>
#include <limits>
#include <numeric>
#include <iomanip>
#include <sstream>
using namespace std;

int main(){
    string s;
    getline(cin,s);

    vector<string> words;

    stringstream ss(s);

    string word;
    while(ss>> word){
        words.push_back(word);
    }

    for(string &s : words){
        cout<<s<<" ";
    }
    return 0;

}