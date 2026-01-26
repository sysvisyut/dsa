#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = 0; i < n; i++) {
        int max_val = -1;
        int max_idx = -1;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] > max_val) {
                max_val = arr[j];
                max_idx = j;
            }
        }

        if (max_val > arr[i]) {
            reverse(arr.begin() + i, arr.begin() + max_idx + 1);
            break; 
        }
    }

    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}