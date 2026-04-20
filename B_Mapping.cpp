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

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;

    vector<int> arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    unordered_map<int,int> mp;
    unordered_set<int> st(arr.begin(),arr.end());
    vector<int> temp(st.begin(),st.end());

    if(temp.size() == n){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }

    if(temp.size() == m){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }

    return 0;
    



}