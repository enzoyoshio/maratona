#include <bits/stdc++.h>

#define int long long

using namespace std;

using tiii = tuple<int,int,int>;
const int MAXN = 2e5;
int n;
vector<tiii> v;

struct ST {
    vector<int> st;
    int n;
    int el_neutro;

    ST(int n): n(n) {
        el_neutro = -n;
        st.assign(4*n, el_neutro);
    }  

    int f(int a, int b) {
        return max(a, b);
    }

    void update(int idx, int val, int sti, int stl, int str) {
        if(idx > str || idx < stl) return;

        if(stl == str) {
            st[sti] = f(st[sti], val);
            return;
        }

        int mid = (stl+str) >> 1, e = (sti) << 1, d = (sti<<1)+1;

        update(idx, val, e, stl, mid);
        update(idx, val, d, mid+1, str);
        st[sti] = f(st[e], st[d]);
    }

    int query(int A, int B, int sti, int stl, int str) {
        if(A > str || B < stl) return el_neutro;

        if(A <= stl && str <= B) return st[sti];

        int mid = (stl+str) >> 1, e = sti<<1, d = (sti << 1) +1;

        return f(query(A, B, e, stl, mid), query(A, B, d, mid+1, str));
    }

    void update(int idx, int val) {
        update(idx, val, 1, 0, n-1);
    }

    int query(int A, int B) {
        return query(A, B, 1, 0, n-1);
    }
};

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n;
    v.assign(n, tiii{});
    for(auto& [a, b, c]: v)
        cin >> a >> b >> c;

    vector<int> dp(n, -MAXN);
    vector<ST> stLess(6, ST(MAXN)), stGreat(6, ST(MAXN));

    for(int i = 0; i < n; i++) {
        auto [ti, posi, vali] = v[i];
        if(ti - posi < 0) continue;

        dp[i] = vali;
        for(int j = 0; j <= posi; j++)
            dp[i] = max(dp[i], vali + stLess[j].query(0, ti-posi));
        for(int j = posi; j <= 4; j++)
            dp[i] = max(dp[i], vali + stGreat[j].query(0, ti+posi));

        stLess[posi].update(ti-posi, dp[i]);
        stGreat[posi].update(ti+posi, dp[i]);

    }
 
    /*
    for(int i = 0; i < n; i++) 
        cout << dp[i] << ' ';
    cout << endl;
    */

    cout << max(*max_element(dp.begin(), dp.end()), 0LL) << endl;
}

// no optimization
/*
    for(int i = 0; i < n; i++) {

        auto [ti, posi, vali] = v[i];
        
        if(ti-posi >= 0) 
            dp[i] = vali;

        for(int j = max(i-5, 0LL); j < i; j++) {
            auto [tj, posj, valj] = v[j];

            if(ti - tj >= abs(posi - posj) && dp[j] >= 0) 
                dp[i] = max(dp[i], vali + dp[j]);
        }
    }  
*/
