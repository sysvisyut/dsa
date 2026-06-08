#include <iostream>

using namespace std;

int main() {

    int h,w;
    cin >> h>>w;

    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            int b = 0;

            
            if (i-1 >= 1) b++;
            if (i+1 <= h) b++;
            if (j-1 >= 1) b++;
            
            if (j+1 <= w) b++;

            cout << b << (j == w ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}