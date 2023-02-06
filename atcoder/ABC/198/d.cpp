#include <bits/stdc++.h>

using namespace std;

int main() {
    string s, t, u;
    cin >>  s >> t >> u;

    vector<int> f(26, 0);
    for(auto ch: s) f[ch-'a']=1;
    for(auto ch: t) f[ch-'a']=1;
    for(auto ch: u) f[ch-'a']=1;

    if(accumulate(f.begin(), f.end(), 0) > 10) return cout << "UNSOLVABLE\n", 0;

    string teste = "";
    for(int i = 0; i < 26; i++) if(f[i]) teste += char(i + 'a');

    vector<int> next = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> to(26, 0);

    do {

        for(int i = 0; i < teste.size(); i++) {
            to[teste[i]-'a'] = next[i];
        }

        long long ss=0, tt = 0, uu = 0;
        if(!to[s[0]-'a'] || !to[t[0]-'a'] || !to[u[0]-'a']) continue;
        for(auto el: s) ss = (ss*10 + to[el-'a']);
        for(auto el: t) tt = (tt*10 + to[el-'a']);
        for(auto el: u) uu = (uu*10 + to[el-'a']);

        if(ss + tt == uu) return cout << ss << endl << tt << endl << uu << endl, 0;
    }while(next_permutation(next.begin(), next.end()));
    cout << "UNSOLVABLE\n";
}
