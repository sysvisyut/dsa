#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }

        unordered_map<int,int> mp;
        for(int x : arr){
            mp[x]++;
        }

        if(mp.size() > 2){
            cout << "No\n";
            continue;
        }

        if(mp.size() == 1){
            cout << "Yes\n";
            continue;
        }

        vector<long long> freq;
        for(auto &p : mp){
            freq.push_back(p.second);
        }

        long long f1 = freq[0];
        long long f2 = freq[1];

        if(f1 == f2){
            cout << "Yes\n";
        }
        else if(n % 2 == 1 && abs(f1 - f2) == 1){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
    }
}