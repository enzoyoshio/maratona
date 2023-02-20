#include <bits/stdc++.h>

#define int long long

using namespace std;

vector<int> ord;

inline int find(int x) {
    return lower_bound(ord.begin(), ord.end(), x) - ord.begin();
}

struct ST {
    vector<int> st;
    int n;
    int el_neutro=(int)-1e18;

    ST(int n): n(n) {
        st.assign(4*n, el_neutro);
    }

    ST(vector<int>& v) {
        n = v.size();
        st.assign(4*n, el_neutro);
        build(v, 1, 0, n-1);
    }

    inline int f(int a, int b) {
        return max(a, b);
    }

    void build(vector<int>& v, int sti, int stl, int str) {
        if(stl == str) {
            st[sti] = v[stl];
            return;
        }

        int mid = (stl+str) >> 1, e = sti<<1, d = (sti<<1)+1;

        build(v, e, stl, mid);
        build(v, d, mid+1, str);
        st[sti] = f(st[e], st[d]);
    } 

    void update(int idx, int val, int sti, int stl, int str) {
        if(idx > str || idx < stl) return;

        if(stl == str) {
            st[sti] = f(st[sti], val);
            return;
        }

        int mid = (stl+str) >> 1, e = sti<<1, d = (sti<<1)+1;

        update(idx, val, e, stl, mid);
        update(idx, val, d, mid+1, str);
        st[sti] = f(st[e], st[d]);
    }

    int query(int A, int B, int sti, int stl, int str) {
        if(A > str || B < stl) return el_neutro;

        if(A <= stl && str <= B) return st[sti];

        int mid = (stl+str)>>1, e = sti << 1, d = (sti<<1)+1;
        
        return f(query(A, B, e, stl, mid), query(A, B, d, mid+1, str));
    }

    void update(int idx, int val) {
        update(idx, val, 1, 0, n-1);
    }

    int query(int A, int B) {
        if(A > B) return el_neutro;
        return query(A, B, 1, 0, n-1);
    }
};

#define db(x) cerr << "[ " << #x << " = " << x << " ]\n"

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, c;
    cin >> n >> c;
    vector<int> custo(n), pos(n), pref(n), suf1(n), suf2(n);

    for(int i = 0; i < n; i++) {
        cin >> pos[i] >> custo[i];
        ord.push_back(pos[i]);
    }

    for(int i = 0; i < n; i++)
        pref[i] = suf1[i] = suf2[i] = custo[i];

    for(int i = 1; i < n; i++) 
        pref[i] += pref[i-1];

    for(int i = 0; i < n; i++)
        pref[i] -= pos[i];

    for(int i = n-2; i >= 0; i--) 
        suf1[i] += suf1[i+1], suf2[i] += suf2[i+1];

    for(int i = n-1; i >= 0; i--) {
        suf1[i] = suf1[i] - (c-pos[i]); 
        suf2[i] = suf2[i] -  2*(c-pos[i]);
        ord.push_back(c-pos[i]);
    }
    sort(ord.begin(), ord.end());

    ST st1(ord.size()), st2(ord.size());
    int ans = 0;
    for(int i = n-1; i >= 0; i--) {
        int cur = pref[i];

        /*
        cout << "\n\ndbg\n";
        db(cur);
        db(st2.query(0, find(pos[i])-1));
        db(st1.query(find(pos[i]), (int)ord.size()-1));
        */
        ans = max(ans, cur);
        ans = max(ans, max(st1.query(0, (int)ord.size()-1), 0LL));
        ans = max(ans, cur + max(st2.query(0, find(pos[i])-1), 0LL));
        ans = max(ans, cur + max(st1.query(find(pos[i]), (int)ord.size()-1) -pos[i], 0LL));
         
        st2.update(find(c-pos[i]), suf2[i]);
        st1.update(find(c-pos[i]), suf1[i]);
    }

    ans = max(ans, max(st1.query(0, (int)ord.size()-1), 0LL));
    cout << ans << endl;
}
