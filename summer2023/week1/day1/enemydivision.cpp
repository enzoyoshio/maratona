#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);

    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);    
    }

    set<int> group[2];

    for(int i = 0; i < n; i++) group[0].insert(i);

    while(true) {
        bool stop = true;
        set<int> apaga;
        for(auto el: group[0]) {
            int qt = 0;
            for(auto viz: g[el]) if(group[0].find(viz) != group[0].end() && apaga.find(viz) == apaga.end()) {
                qt++;
            } 
            if(qt > 1) {
               apaga.insert(el);
            }
        }

        for(auto el: apaga) {
            group[0].erase(el);
            group[1].insert(el);
        }

        for(auto el: group[1]) {
            int qt = 0;
            for(auto viz: g[el]) if(group[1].find(viz) != group[1].end()) 
                qt++;
            if(qt > 1)
                stop = false;
        }

        if(stop) break;
        swap(group[0], group[1]);
    }

    if(group[1].empty()) {
        cout << 1 << endl;
        for(auto it: group[0]) cout << it << ' '; cout << endl;
    }else {
        cout << 2 << endl;
        for(auto it: group[0]) cout << it+1 << ' '; cout << endl;
        for(auto it: group[1]) cout << it+1 << ' '; cout << endl;
    }
}
