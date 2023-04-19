#include <bits/stdc++.h>

using namespace std;

using tiii = tuple<int,int,int>;
const int oo = 1e9;
int n;
vector<tiii> v;
int tb[18][(1 << 18)];

int dp(int idx, int bit) {

	auto [a1, b1, c1] = v[idx];
	if(__builtin_popcount(bit) == n) {
		if(idx == 0) return 0;
		
		auto [a2, b2, c2] = v[0];
		return abs(a1-a2) + abs(b1-b2) + max(0, c2-c1); 
	}

	auto& res = tb[idx][bit];

	if(~res) return res;

	int ans = oo;

		
	for(int i = 0; i < n; i++) {
		auto [a2, b2, c2] = v[i];
		if(i == idx) continue;
		if((bit & (1 << i)) != 0) continue;

		bit |= (1 << i);
		ans = min(ans, abs(a1-a2) + abs(b1-b2) + max(0, c2-c1) + dp(i, bit));
		bit ^= (1 << i);
	}

	return res = ans;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	
	memset(tb, -1, sizeof tb);

	cin >> n;
	v.assign(n, {});
	for(auto& [a, b, c]: v)
		cin >> a >> b >> c;

	cout << dp(0, 1) << endl;
}
