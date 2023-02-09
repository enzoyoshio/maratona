#include <bits/stdc++.h>

#define int long long

using namespace std;

const int MAXN = 6e5;

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, x;
    cin >> n >> x;
    vector<int> freq(MAXN, 0);

    for(int i = 0; i < n; i++) {
        int fact; cin >> fact;
        freq[fact]++;
    }

    for(int i = 1; i+1 < MAXN; i++) {
        freq[i+1] += freq[i]/(i+1);
        freq[i] %= (i+1);
    }

    for(int i = 1; i < MAXN; i++) {
        if(freq[i] && i < x) 
            return cout << "No\n", 0;
    }

    cout << "Yes\n";
}
