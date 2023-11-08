#include <bits/stdc++.h>

using namespace std;
#define int long long

const int oo = 1e18;
int n, x;
vector<int> v;
map<pair<int,int>,int> dp;

int up(int x, int d) { return (x+d-1)/d * d;}
int down(int x, int d) { return (x/d) * d;}

int f(int cur, int idx) {

	if(idx == n-1) {
		return cur/v[idx];
	}

	if(dp.find({cur, idx}) != dp.end()) return dp[{cur, idx}];
	int prox = v[idx+1];
	int upper = up(cur, prox);
	int dow = down(cur, prox);
	int first = (upper - cur)/v[idx] + f(upper, idx+1);
	int second = (cur - dow)/v[idx] + f(dow, idx+1);
	return dp[{cur, idx}] = min(first, second);
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	cin >> n >> x;
	v.resize(n);
	for(auto& it: v) cin >> it;
	int ans = f(x, 0);
	cout << ans << endl;
}
