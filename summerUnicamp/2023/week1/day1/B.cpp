#include <bits/stdc++.h>

#define int long long

using namespace std;

const int MAXN = 1e5+8;
int n;
vector<int> st(4*MAXN);

int f(int a, int b) {
    return a+b;
}

void update(int idx, int val, int sti=1, int stl=0, int str=n-1) {
    if(idx > str || idx < stl) return;

    if(idx == stl && idx == str) {
        st[sti] += val;
        return;
    }

    int mid = (stl+str)/2, e = 2*sti, d = 2*sti+1;

    update(idx, val, e, stl, mid);
    update(idx, val, d, mid+1, str);

    st[sti] = f(st[e], st[d]);
}

int query(int A, int B, int sti=1, int stl=0, int str=n-1) {
    if(A > B) return 0;
    if(A > str || B < stl) return 0;

    if(A <= stl && str <= B) return st[sti];

    int mid = (stl+str)/2, e = 2*sti, d = 2*sti+1;

    return f(query(A, B, e, stl, mid), query(A, B, d, mid+1, str));
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n;
    vector<int> v(n);
    for(auto& it: v) cin >> it, it--;

    vector<int> maior(n, 0), menor(n, 0);

    for(int i = 0; i < 4*MAXN; i++) st[i] = 0;

    for(int i = 0; i < n; i++) {
        maior[i] = query(v[i]+1, n-1);
        update(v[i], 1);
    }

    for(int i =0; i < 4*MAXN; i++) st[i] = 0;

    for(int i = n-1; i >= 0; i--) {
        menor[i] = query(0, v[i]-1);

        update(v[i], 1);
    }

    int ans = 0;

    for(int i = 0; i < n; i++) 
        ans += menor[i]*maior[i];

    cout << ans << endl;
}
