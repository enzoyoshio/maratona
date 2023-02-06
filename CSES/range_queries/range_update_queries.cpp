#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 3e5;
int n, q;
vector<int> v(MAXN), st(4*MAXN, 0);

void update(int a, int b, int val, int sti=1, int stl=0, int str=n-1) {
    if(a > str || b < stl) return;

    if(a <= stl && str <= b) {
        st[sti] += val;
        return;
    }

    int mid = (stl+str) >> 1, e = 2*sti, d = 2*sti+1;

    update(a, b, val, e, stl, mid);
    update(a, b, val, d, mid+1, str);
}

int query(int point, int sti=1, int stl=0, int str=n-1) {
    if(stl > point || str < point) return 0;

    if(stl == str) return st[sti];

    int mid = (stl+str)>>1, e = 2*sti, d = 2*sti+1;

    return st[sti] + query(point, e, stl, mid) + query(point, d, mid+1, str);
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> q;
    for(int i = 0; i < n; i++) cin >> v[i];
    for(int i = 0; i < n; i++) update(i, i, v[i]);

    while(q--) {
        int t; cin >> t;
        if(t == 1) {
            int a, b, u; cin >> a >> b >> u; a--, b--;
            update(a, b, u);
        }else {
            int k; cin >> k; k--;
            cout << query(k) << endl;
        }
    }    
}
