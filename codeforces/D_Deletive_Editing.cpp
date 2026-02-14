#include <iostream>

using namespace std;


void solve(){
    string s1,s2;
    cin>>s1>>s2;
    int n = s1.size();
    int m = s2.size();


    vector<int> freq(26,0);

    for(int i=0;i<m;i++){
        freq[s2[i]-'A']++;
    }

    for(int i=n-1;i>=0;i--){
        if(freq[s1[i]-'A'] > 0){
            freq[s1[i]-'A']--;
        }
        else{
            s1[i] = '.';
        }
    }
    string t = "";

    for(int i=0;i<n;i++){
        if(s1[i] != '.'){
            t+=s1[i];
        }
    }

    if(t==s2){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }



}
int main(){
    int t;
    cin>>t;

    while(t--){
        solve();
    }
}