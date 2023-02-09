#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t; while(t--) {
        int n; cin >> n;
        for(int i = 1; i <= (n+1)/2; i++) {
            if(n%2 == 0) {
                cout << n/2 + i << ' ' << i << ' ';
            }else {
                if(i != (n+1)/2)
                    cout << i << ' ' << (n+1)/2 + i << ' ';
                else 
                    cout << i;
            }
        }
        cout << endl;
    }
}
