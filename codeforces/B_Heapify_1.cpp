#include <iostream>
#include <vector>

using namespace std;

int odd_part(int n) {
    while (n % 2 == 0) {
        n /= 2;
    }
    return n;
}
void solve(){
    int n;
    cin>>n;

    vector<int> arr(n);
   
    bool ok = true;

   for (int i = 0; i < n;i++) {
        cin >> arr[i];
        
     
        if (odd_part(arr[i]) != odd_part(i + 1)) {
            ok = false;
        }
    }
    if (ok) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    

   
}

int main(){
    int t;
    cin>>t;

    while(t--){
        solve();
    }
}