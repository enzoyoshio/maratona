#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
vector<int> vis;

bool has_cycle(int idx, int p) {
    
    vis[idx] = 2;

    bool ans = false; 
    for(auto filho: g[idx]) if(filho != p) {
        if(vis[filho] == 2) {
            return true;
        }

        if(!vis[filho]) 
            ans |= has_cycle(filho, idx);
    }

    vis[idx] = 1;
    return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n;
    cin >> n;
    int counter = 1;
    map<string, int> m;
    g.assign(2*n+10, vector<int>());
    vis.assign(2*n+10, 0);
    set<pair<int,int>> read;
    bool can = true;

    for(int i = 0; i < n; i++) {
        string a, b; 
        cin >> a >> b;
        int aa, bb;
        if(!m[a]) m[a] = counter++;
        if(!m[b]) m[b] = counter++;
        aa = m[a];
        bb = m[b];
        if(read.find(make_pair(bb, aa)) != read.end())
            can = false;

        g[aa].push_back(bb);
        g[bb].push_back(aa);
        read.emplace(aa, bb);
    }

    if(!can) 
        return cout << "No\n", 0;

    for(int i = 1; i < counter; i++) {
        if(!vis[i] && has_cycle(i, i)) {
            return cout << "No\n", 0;
        }
    }
    cout << "Yes\n";
}
