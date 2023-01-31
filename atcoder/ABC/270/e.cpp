#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for(auto& it: v) cin >> it;

    int soma = accumulate(v.begin(), v.end(), 0LL);

    if(soma == k) {
        for(int i = 0; i < n; i++)
            cout << 0 << ' ';
        cout << endl;
        return 0;
    }
    set<pair<int,int>> alli;

    for(int i = 0; i < n; i++)
        if(v[i])
            alli.emplace(v[i], i);

    int mn = 0;
    int total = 0;
    int nivel = 0;

    // first thing to do
    // take the 
    while(alli.size()) {
        ///cout << "nivel = " << nivel << " tamanho de nao zero- elementos " << alli.size() << endl;
        ///cout << "k = " << k << endl;
        int menor = alli.begin()->first;
        ///cout << "menor = " << menor << endl;
      ///  cout << "expr = " << (int)alli.size()* (menor-nivel) << endl;
        if((int)alli.size() *( menor-nivel) >= k) {
            // i am subtracting 
            // by the integer division
    ///        cout << "nivel before " << nivel << endl;
            nivel += k/(int)alli.size();
  ///          cout << "nivel after " << nivel << endl;
            k %= (int)alli.size();
            break;
        }
        k -= (int)alli.size() * (menor-nivel);
        while(alli.size() && alli.begin()->first == menor) {
            alli.erase(alli.begin());
        }
        nivel += menor-nivel;
    }

///    cout << "last k = " << k << endl;

    vector<int> ans(n, 0);
    vector<pair<int,int>> gera;
    for(auto [val, idx]: alli) gera.emplace_back(idx, val);
    sort(gera.begin(), gera.end());
    for(auto [idx, val]: gera) ans[idx] = val - nivel + (k > 0 ? -1:0), k--;

    for(auto it: ans) cout <<  it << ' '; cout << endl;
}
