#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        string s;
        cin>>n;
        cin>>s;
        int curr = 1; 
        int max_len =1;
        
        for(int i=1;i<n;i++){
            if(s[i] == s[i-1]){
                curr++;
                max_len = max(max_len,curr);
            }
            else{
                curr=1;
            }
        }

        cout<<max_len+1<<endl;
    }
}