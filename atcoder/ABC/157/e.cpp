#include <bits/stdc++.h>

using namespace std;

struct ST {
    vector<int> st;
    int n, el_neutro=0;

    ST(int n): n(n) {
        st.assign(4*n, 0);
    }

    int f(int a, int b) {
        return max(a, b);
    }

    int update(int idx, int val, int sti, int stl, int str) {
        if(idx < stl || idx > str) return st[sti];

        if(stl == str) return st[sti] = val;

        int mid = (stl+str)>>1, e = sti<<1, d = (sti<<1)+1;

        return st[sti] = f(update(idx, val, e, stl, mid), update(idx, val, d, mid+1, str));
    }

    int query(int A, int B, int sti, int stl, int str) {
        if(A > str || B < stl) return el_neutro;

        if(A <= stl && str <= B) 
            return st[sti];

        int mid = (stl+str)>>1, e = sti<<1, d = (sti<<1)+1;

        return f(query(A, B, e, stl, mid), query(A, B, d, mid+1, str));
    }

    int update(int idx, int val) {
        return update(idx, val, 1, 0, n-1);
    }

    int query(int A, int B) {
        return query(A, B, 1, 0, n-1);
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, q;
    string s;
    cin >> n >> s >> q;
    vector<ST> alpha(26, ST(n));
    for(int i = 0; i < n; i++)
        alpha[s[i]-'a'].update(i, 1);

    while(q--) {
        int type; cin >> type;

        if(type == 1) {
            int i; char c;
            cin >> i >> c;
            i--;
            alpha[s[i]-'a'].update(i, 0);
            s[i] = c;
            alpha[s[i]-'a'].update(i, 1);
        }else {
            int l, r; cin >> l >> r;
            l--, r--;
            int ans = 0;
            for(int i = 0; i < 26; i++)
                ans += alpha[i].query(l, r);
            cout << ans << endl;
        }
    }
}
