#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;


int helper(int num){
    int fact=0;
    while(num > 0 && num%2 ==0){
        fact++;
        num/=2;
    }

    return fact;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n);

        long long two_cnt=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            two_cnt+=helper(arr[i]);
  
        }
        if(two_cnt >= n){
            cout<<0<<endl;
            continue;
        }
        vector<int>ind;

        for(int i=1;i<=n;i++){
            ind.push_back(helper(i));
        }
        sort(ind.rbegin(),ind.rend());
        int op =0;
        bool valid = false;
        for(int i=0;i<ind.size();i++){
            two_cnt+=ind[i];
            op++;
            
            if(two_cnt >=n){
                cout<<op<<endl;
                valid= true;
                break;
            }
        }

        if(!valid){
            cout<<-1<<endl;
        }


        
    }
}