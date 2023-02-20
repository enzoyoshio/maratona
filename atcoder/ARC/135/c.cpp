#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> freq(33, 0);
    for(int i = 0; i < n; i++) {
        int num; cin >> num;
        bitset<33> s(num);
        for(int i = 0; i < 33; i++)
            freq[i] += s[i];
    }

    int ans = 0;
    for(int i = 0; i < 33; i++) {
        if(freq[i])
            ans += (1LL << i) * max(freq[i], n-freq[i]);
    }

    cout << ans << endl;
}
