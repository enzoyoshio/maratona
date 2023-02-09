#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    cin.tie(0)->sync_with_stdio(false);

   int n;
    cin >> n;
    vector<int> v(n), pref(n);
    for(auto& it: v) 
        cin >> it;

    sort(v.begin(),v.end());
    for(int i = 0; i <n; i++) {
        pref[i] = v[i];
        if(i) 
            pref[i] += pref[i-1];
    }

    for(int i = n-1; i; i++) {
        if(pref[i-1] <= pref.back() - pref[i-1]) {
            cout << (pref.back()-pref[i-1]) * 2 << endl;
            return 0;
        }
    }
    assert(false);
}
