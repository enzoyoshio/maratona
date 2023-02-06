#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MOD = 998244353;
int n, k;
vector<vector<int>> v;

struct DSU {
    vector<int> pai, tam;

    DSU(int n) {
        pai.assign(n, 0);
        tam.assign(n, 1);

        iota(pai.begin(), pai.end(), 0LL);
    }

    int find(int x) { return x == pai[x] ? x : pai[x] = find(pai[x]);}

    void join(int a, int b) {
        a = find(a);
        b = find(b);
        if(a == b) return;
        if(tam[a] < tam[b]) swap(a, b);
        tam[a] += tam[b];
        pai[b] = a;
    }
};

int f(int n) {
    int no = 1;
    for(int i = 1; i <= n; i++) no = (no*i)%MOD;

    return no;
}

bool check(int l, int r, bool dir) {

    if(dir) {
        for(int i = 0; i < n; i++) {
            if(v[l][i] + v[r][i] > k) return false;
        }
    }else {
        for(int i = 0; i < n; i++)
            if(v[i][l] + v[i][r] > k) return false;
    }
    return true;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> k;
    v.assign(n, vector<int>(n));
    DSU dsuCol(n), dsuLin(n);

    for(auto& line: v) 
        for(auto& it: line)
            cin >> it;

    for(int linha = 0; linha < n; linha++) {
        for(int coluna = 0; coluna < n; coluna++) {
            for(int col2 = coluna+1; col2 < n; col2++) {
                if(check(coluna, col2, 0)) {
                    dsuCol.join(coluna, col2);
                }
            }
        }
    }

    for(int coluna = 0; coluna < n; coluna++) {
        for(int linha = 0; linha < n; linha++) {
            for(int linha2 = linha+1; linha2 < n; linha2++) {
                if(check(linha, linha2, 1)) {
                    dsuLin.join(linha, linha2);
                }
            }
        }
    }

    int ans = 1;
    for(int i = 0; i < n; i++) {
        int cols = dsuCol.find(i);
        if(cols == i) { 
            ans = (ans * f(dsuCol.tam[i]))%MOD;
             
        }
        cols = dsuLin.find(i);
        if(cols == i)
            ans = (ans * f(dsuLin.tam[i]))%MOD;
    }

    cout << ans << endl;

}
