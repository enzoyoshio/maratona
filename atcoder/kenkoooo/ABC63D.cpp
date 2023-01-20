#include <bits/stdc++.h>

#define int long long

using namespace std;

int n, a, b;
vector<int> v;

bool check(int t) {
    int soma = 0;
    for(int i = 0; i < n; i++) {
        // se eu consigo matar so com operacao b
        if(t*b >= v[i]) continue;
        int rest = v[i] - t*b;
        int dif = a-b;
        soma += (rest+dif-1)/dif;
    }
    return soma <= t;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> a >> b;
    v.assign(n, 0);
    for(auto& it: v) cin >> it;

    int l = 1, r = 1e9;
    int ans = r;

    while(l <= r) {
        int mid = (l+r)/2;

        if(check(mid)) r = mid-1, ans = mid;
        else l = mid+1;
    }

    cout << ans << '\n';
}
