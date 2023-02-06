#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 3e5;
int n, m;
vector<int> st(4*MAXN, 0), volta(MAXN);
vector<pair<int,int>> v(MAXN);

void update(int idx, int val, int sti=1, int stl=0, int str=n-1) {
    if(idx > str || idx < stl) return;

    if(stl == str) {
        st[sti] = val;
        return;
    }

    int mid = (stl+str)>>1, e = 2*sti, d = 2*sti+1;

    update(idx, val, e, stl, mid);
    update(idx, val, d, mid+1, str);

    st[sti] = st[e] + st[d];
}

int query() {
    return st[1];
}

signed main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> v[i].first; v[i].second = i;
    }

    sort(v.begin(), v.begin()+n);

    for(int i = 0; i < n; i++) {
        volta[v[i].second] = i;
    }

    for(int i = 0; i < n; i++) {
        update(i, (i == 0 || v[i-1].second > v[i].second));
    }

    while(m--) {
        int a, b; cin >> a >> b;
        a--, b--;
        swap(volta[a], volta[b]);
        a = volta[a], b = volta[b];
        
        swap(v[a].second, v[b].second);
        update(a, (a == 0 || v[a-1].second > v[a].second));
        if(a+1 < n) 
            update(a+1, (v[a].second > v[a+1].second));
        update(b, (b == 0 || v[b-1].second > v[b].second));
        if(b+1 < n) 
            update(b+1, (v[b].second > v[b+1].second));

        cout << query() << endl;
    }
}
