#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<int> v(n), t(m);
    for(auto& it: v)
        cin >> it;
    for(auto& it: t)
        cin >> it;

    for(int i = 1; i < n; i++)
        v[i] += v[i-1];
    for(int i = 1; i < m; i++)
        t[i] += t[i-1];

    int fp = 0, sp = 0;
    int fsum = 0, ssum = 0;
    int ans = 0;

    while(fp < n && sp < m) {
        if(v[fp] == t[sp]) {
            ans++;
            fp++, sp++;
            continue;
        }
        if(v[fp] < t[sp])
           fp++;
        else 
           sp++; 
    }
    cout << ans << endl;
}
