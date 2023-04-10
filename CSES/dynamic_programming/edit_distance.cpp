#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
const int MAXN = 5050;
int n, m;
string s, t;
int dp[MAXN][MAXN];
 
int edit(int ids, int idt) {
 
    if(ids < 0) return idt+1;
    if(idt < 0) return ids+1;
 
    auto& ans = dp[ids][idt];
 
    if(~ans) return ans;
 
    int res = min(edit(ids, idt-1) + 1, edit(ids-1, idt) + 1);
    res = min(res, edit(ids-1, idt-1) + (s[ids] != t[idt]));
 
    return ans = res;
}
 
signed main() {
	memset(dp, -1, sizeof dp);
    cin >> s >> t;
    n = s.size();
    m = t.size();
 
    cout << edit(n-1, m-1) << endl;
}
