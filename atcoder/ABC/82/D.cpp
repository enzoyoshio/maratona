#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
const int ZERO = 5e4;
int tb[2][MAXN];
vector<int> horizontal, vertical;

/*
bool dp(int idx, int soma, bool dir) {

    int n = (dir ? horizontal.size() : vertical.size());
    if(idx >= n)
        return soma == 0;

    if(tb.find({idx, soma}) != tb.end()) return tb[{idx, soma}]; 

    if(dir) 
        return tb[{idx, soma}] = dp(idx+1, soma+horizontal[idx], dir) || dp(idx+1, soma-horizontal[idx], dir);

    return tb[{idx, soma}] = dp(idx+1, soma+vertical[idx], dir) || dp(idx+1, soma-vertical[idx], dir);
}
*/

int main() {
    cin.tie(0)->sync_with_stdio(false);

    string s;
    int x, y;
    cin >> s >> x >> y;
    s += 'T';
    bool hor = 1;
    int sum = 0;

    for(auto ch: s) {
        if(ch == 'T') {
            if(hor) horizontal.push_back(sum);
            else vertical.push_back(sum);
            sum = 0;
            hor = !hor;
            continue;
        }
        sum++;
    }


    /*
    cout << "\n\ncomecou o debug\n";
    for(auto it: horizontal) cout << it << ' '; cout << endl;
    for(auto it: vertical) cout << it << ' '; cout << endl;
    */

    int first = horizontal[0];
    horizontal.erase(horizontal.begin());

    x += ZERO;
    y += ZERO;

    for(int i = 0; i < MAXN; i++) tb[0][i] = tb[1][i] = 0;
    tb[0][ZERO] = 1;

    int n = horizontal.size();
    for(int idx = 0; idx < n; idx++) {
        for(int soma = 0; soma < MAXN; soma++) 
            tb[1][soma] = 0;
        for(int soma = 0; soma < MAXN; soma++) {
            if(soma - horizontal[idx] >= 0) 
                tb[1][soma] |= tb[0][soma-horizontal[idx]];

            if(soma + horizontal[idx] < MAXN)
                tb[1][soma] |= tb[0][soma+horizontal[idx]];
        }  
        swap(tb[0], tb[1]);
    } 

    bool horizonte = tb[0][x-first];

    for(int i = 0; i < MAXN; i++) tb[0][i] = tb[1][i] = 0;
    tb[0][ZERO] = 1;

    n = vertical.size();
    for(int idx = 0; idx < n; idx++) {
        for(int soma = 0; soma < MAXN; soma++) 
            tb[1][soma] = 0;
        for(int soma = 0; soma < MAXN; soma++) {
            if(soma - vertical[idx] >= 0) 
                tb[1][soma] |= tb[0][soma-vertical[idx]];

            if(soma + vertical[idx] < MAXN)
                tb[1][soma] |= tb[0][soma+vertical[idx]];
        }  
        swap(tb[0], tb[1]);
    } 
    bool vert = tb[0][y]; 

//    cout << horizonte << ' ' << vert << '\n';

    if(horizonte && vert) cout << "Yes\n";
    else cout << "No\n";
}
