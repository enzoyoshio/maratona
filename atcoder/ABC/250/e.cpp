#include <bits/stdc++.h>

#define int long long

using namespace std;

using ull = unsigned long long;

struct ST {
    vector<ull> st;
    int n;
    int mod = 1e9+7;
    int p = 31;

    ST(int n): n(n) { st.assign(4*n, 0LL);}

    int fexp(int b, int e) {
        if(e == 0) return 0LL;

        int x = fexp(b, e/2);
        x = (x*x)%mod;
        if(e%2) x = (x*b)%mod;
        return x;
    }

    ull mix(ull o){
        o+=0x9e3779b97f4a7c15;
        o=(o^(o>>30))*0xbf58476d1ce4e5b9;
        o=(o^(o>>27))*0x94d049bb133111eb;
        return o^(o>>31);
        //Those constants supposedly are chosen to give this function better pseudo-random properties, but on any on-site contest, when one can't have team reference document/doesn't want to waste time searching it for implementation typing arbitrary large odd numbers by hand should be good enough
    }
    int f(int a, int b) {
        return mix(a^mix(b));
        return (a+b)%mod;
    }

    void update(int idx, int val, int sti, int stl, int str) {
        if(idx > str || idx < stl) return;

        if(stl == str) {
            st[sti] = val;
            //if(val) st[sti] = fexp(p, idx+1);
            return;
        }

        int mid = (stl+str) >> 1, e = sti << 1, d = (sti<<1) + 1;

        update(idx, val, e, stl, mid);
        update(idx, val, d, mid+1, str);

        st[sti] = f(st[e], st[d]);
    }

    int query(int A, int B, int sti, int stl, int str) {
        if(A > str || B < stl) return 0;

        if(A <= stl && str <= B) return st[sti];

        int mid = (stl+str) >> 1, e = sti << 1, d = (sti << 1) + 1;
        return f(query(A, B, e, stl, mid), query(A, B, d, mid+1, str));
    }

    void update(int idx, int val) {
        update(idx, val, 1, 0, n-1);
    }

    int query(int A, int B) {
        return query(A, B, 1, 0, n-1);
    }
};

vector<int> ord;

int find(int x) {
    return lower_bound(ord.begin(), ord.end(), x) - ord.begin();
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(auto& it: a) 
        cin >> it, ord.push_back(it);
    for(auto& it: b)
        cin >> it, ord.push_back(it);

    sort(ord.begin(), ord.end());

    ST stA(ord.size()), stB(ord.size());
    vector<int> hashA(n), hashB(n);

    for(int i = 0; i < n; i++) {
        stA.update(find(a[i]), a[i]);
        stB.update(find(b[i]), b[i]);
        hashA[i] = stA.query(0, stA.n-1);
        hashB[i] = stB.query(0, stB.n-1);
    } 

    int q;
    cin >> q;
    while(q--) {
        int x, y; cin >> x >> y; x--, y--;
        if(hashA[x] == hashB[y]) cout << "Yes\n";
        else cout << "No\n";
    }
}
