#include <iostream>
#include <vector>
using namespace std;


int helper(string s, string ok){
    int op = 0;
    int check_ind = ok.size()-1;

    for(int i= s.size()-1; i>=0; i--){
        if(s[i] == ok[check_ind]){
            check_ind--;
            if(check_ind < 0){
                break;
            }
        }
        else{
            op++;
        }
    }

    if(check_ind >= 0){
        op = INT_MAX;
    }

    return op;
}
int main(){
    long long t;
    cin>> t;

    while(t--){
        string s;
        cin>>s;
        vector<string> ok = {"00","25","75","50"};

        
        int ans = INT_MAX;

        for(auto it: ok){
            ans = min(ans, helper(s,it));
        }

        cout<< ans<< endl;

       
    }
}