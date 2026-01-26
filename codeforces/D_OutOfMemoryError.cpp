#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n, m;
    long long h;
    cin >> n >> m >> h;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
   
    vector<long long> added(n, 0);
    vector<int> last(n, 0);
    
    int curr = 1; 

    for (int i = 0; i < m; i++) {
        int b;
        long long c;
        cin >> b >> c;
        b--; 

      
        if (last[b] != curr) {
            added[b] = 0;
            last[b] = curr;
        }

     
        if (a[b] + added[b] + c > h) {
          
            curr++;
        } else {
            
            added[b] += c;
        }
    }

   
    for (int i = 0; i < n; i++) {
        long long final_val = a[i];
        
       
        if (last[i] == curr) {
            final_val += added[i];
        }
        
        cout << final_val << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}