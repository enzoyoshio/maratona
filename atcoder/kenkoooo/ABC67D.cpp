#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5+10;
int n;
vector<int> g[MAXN];
vector<int> di(MAXN);
vector<int> path;
vector<int> parent(MAXN);

void ff(int orig, int pai) {
    parent[orig] = pai;
    for(auto filho: g[orig]) if(filho != pai) 
        ff(filho, orig); 
} 

int tam(int u, int v) {
    int t = 1;
    for(auto w: g[u]) if(w != v) {
        t += tam(w, u);
    }

    return t;
}

int main() {
    // cin.tie(0)->sync_with_stdio(false);

    cin >> n;
    for(int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    ff(1, 1);
    for(int curr = parent[n]; curr != parent[curr]; curr = parent[curr])
        path.push_back(curr);
    int tt = path.size();
    int t1, t2;
    // se eles forem vizinhos;
    if(tt == 0) {
        t1 = tam(1, n);
    }else if(tt == 1) { // se so tiver um cara entre eles
        t1 = tam(path[0], n);
    }else { // se tiver mais de um cara entre
            // o menor caminho entre eles
        reverse(path.begin(), path.end());
        int pai1 = (tt)/2;

        if(tt%2 == 0) pai1--;
        t1 = tam(path[pai1], path[pai1+1]);
    }

    t2 = n-t1;
    if(t1 > t2) cout << "Fennec\n";
    else cout << "Snuke\n";
}
