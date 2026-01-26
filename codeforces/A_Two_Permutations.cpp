#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;


int main()
{

    int t;
    cin >> t;
    while (t--) 
    {
        int n,a,b;
        cin>>n>>a>>b;

        if((a+b+2 <= n) || (a==b && a==n)){
            cout<<"Yes"<<endl;
            continue;
        }
        else{
            cout<<"No"<<endl;
            continue;
        }
       
    }
    return 0;
}

