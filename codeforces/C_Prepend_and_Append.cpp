#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;


int solve(){
        int n;
        cin>>n;
        string s;
        cin>>s;

        int i = 0;
        int j = n-1; 
        while(i<=j){
            if(s[i] == s[j]){
               return j-i+1;
               break;
            }
            else{
                i++;
                j--;
            }
        }
        return 0;
        
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int ans = solve();
        cout<<ans<<endl;
   
    }
    return 0;
}