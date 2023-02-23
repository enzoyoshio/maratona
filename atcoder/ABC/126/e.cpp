#include <bits/stdc++.h>

using namespace std;

struct dsu {
    vector<int> pai;
    int n;

    dsu(int n): n(n) {
        pai.resize(n);
        iota(pai.begin(), pai.end(), 0);
    }

    int find(int x) {
        return x == pai[x] ? x : pai[x] = find(pai[x]);
    }

    void join(int x, int y) {
        x = find(x);
        y = find(y);

        if(x == y) return;

        pai[y] = x;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    dsu d(n);
    for(int i = 0; i < m; i++) {
        int a, b, w; cin >> a >> b >> w;
        a--, b--;
        d.join(a, b);
    }

    int ans = 0;
    for(int i = 0; i < n; i++)
        ans += d.find(i) == i;

    cout << ans << endl;
}
