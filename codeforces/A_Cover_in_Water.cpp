#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int maxi = INT_MIN;
        int cnt =0;
        int cnt1 =0;

        for(char &c : s){
            if(c == '.'){
                cnt++;
                cnt1++;
            }
            else{
                cnt=0;
            }
            maxi = max(cnt,maxi);
        }
        if(maxi < 3){
            cout<<cnt1<<endl;
        }
        else{
            cout<<"2"<<endl;
        }
    }
}