#include <bits/stdc++.h>

#define int long long

using namespace std;

int solve() {
    int n;
    cin >> n;
    if(n%2 == 0) 
        return cout << "No\n", 0;

    cout << "Yes\n";
    int x = 1, y = 2*n;
    while(x <= (n+1)/2) {
        cout << x << ' ' << y << endl;
        x++; y -= 2;        
    }   

    x = n, y += 3;

    while(x > (n+1)/2) {
        cout << x << ' ' << y << endl;
        x--;
        y += 2;
    }
    return 0;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t=1;
    cin >> t;
    while(t--) 
        solve();
}
