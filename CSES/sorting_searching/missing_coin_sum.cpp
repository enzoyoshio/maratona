#include <bits/stdc++.h>

#define int long long 

using namespace std;

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> v(n);
    for(auto& it: v) cin >> it;
    sort(v.begin(), v.end());

    int sum = 0;

    for(int i = 0; i < n; i++) {
        if(sum+1 < v[i]) break;
        sum += v[i];
    }

    cout << sum+1 << endl;

}
