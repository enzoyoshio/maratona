#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n;
    int q;
    cin >> n >> q;

    vector<int> v(2*n-1, -1);

    for(int i = 1; i <= n; i++) {
        v[2*i-2] = i;
    }

    while(v.size() > n) {
        int idx = (int)v.size() -1;
        while(v[idx] != -1) idx--;
        v[idx] = v.back();
        v.pop_back();
    }

    for(int i = 0; i < q; i++) {
        int x;
        cin >> x;

        cout << v[x-1] << endl;
    }
}
