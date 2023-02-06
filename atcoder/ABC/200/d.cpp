#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto& it: v) cin >> it;
    
    vector<vector<int>> somas(200);
//    map<int,int> indexOf;
//    for(int i = 0; i < n; i++) indexOf[v[i]] = i;

    for(int idx = 0; idx < n; idx++) {
        if(somas[0].size()) {
            cout << "yes\n";
            cout << 1 << ' ' << idx+1 << endl;
            cout << somas[0].size() + 1 << ' ';
            for(auto el: somas[0]) cout << el << ' '; cout << idx+1 << endl;

            return 0; 
        }
//        cout << "STarting " << idx << " iteration\n";
        if(somas[v[idx]%200].size()) {

            cout << "yes\n";
            cout << somas[v[idx]%200].size() << ' ';
            for(auto it: somas[v[idx]%200]) cout << it << ' '; cout << endl;
            cout << 1 << ' ' << idx+1 << endl;
            return 0;
        }
        vector<pair<int,int>> adiciona;
        for(int i = 0; i < 200; i++) {
            // se o mod q eu to olhando agora ta vazio, ignoro
            if(somas[i].empty()) continue;
            // found two guys that are equal
            if((somas[(i+v[idx])%200].size())) {
                
//                cout << "OGT HERE WITH " << (i+v[idx])%200 << " MODULO\n";
 //               cout << "now im in " << i << endl;
                cout << "yes\n";
                cout << somas[(i+v[idx])%200].size() << ' ';
                for(auto el: somas[(i+v[idx])%200]) cout << el << ' ';
                cout << endl;
                cout << somas[i].size() + 1 << ' ';
  //              cout << "\ndebug\n";
                for(auto el: somas[i]) cout << el << ' ';
   //             cout << "\nenddebug\n";
                cout << idx+1 << endl;
                return 0;
            }else
                adiciona.emplace_back((i+v[idx])%200, i);
        }

        for(auto [idxPega, el]: adiciona) {
            for(auto valor: somas[el]) somas[idxPega].emplace_back(valor);
            somas[idxPega].emplace_back(idx+1);
        } 
        somas[v[idx]%200].push_back(idx+1);

        /* 
        for(int i = 0; i < 200; i++) {
            if(somas[i].empty()) continue;
            cout << "somando ate " << i << endl;
            for(auto el: somas[i]) cout << el << ' ';
            cout << endl;
        }
        */
        
    }
    cout << "no\n";
}
