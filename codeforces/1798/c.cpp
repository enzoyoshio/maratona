#include <bits/stdc++.h>

using namespace std;

#define int long long

const int oo = 1e12;
const int MAXN = 3e5;
int n;
vector<vector<int>> st(30, vector<int>(MAXN));
vector<pair<int,int>> v(MAXN);
int lg[MAXN+1];

void build() {
	for(int i = 0; i < n; i++)
		st[0][i] = v[i].second;

	for(int i = 1; i <= 23; i++) 
		for (int j = 0; j + (1 << i) <= n; j++)
			st[i][j] = lcm(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
}

int query(int l, int r) {
	int i = lg[r-l+1];

	return lcm(st[i][l], st[i][r- ( 1 << i) + 1]); 
}

void solve() {
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> v[i].first >> v[i].second;

	build();
	int ans = 0;
	for(int i = 0; i < n; i++) {
		int l = i, r = n-1, cur = i;

		while(l <= r) {
			int mid = (l+r) >> 1;

			bool imp = false;
			int lc = 1;
			for(int j = i; j <= mid && !imp; j++) {
				lc = lcm(lc, v[j].second);
				if(lc > oo) imp = true;
			}	

			if(lc > oo) {
				r = mid-1;
				continue;
			}

			for(int j = i; j <= mid && !imp; j++) {
				if(v[j].first % (lc / v[j].second)) imp = 1;
			}

			if(imp) {
				r = mid-1;
				continue;
			}

			cur = mid;
			l = mid+1;
		}
		
		ans++;
		i = cur;
	}

	cout << ans << endl;

}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	lg[1] = 0;
	for (int i = 2; i <= MAXN; i++)
	    lg[i] = lg[i/2] + 1;

	int t = 1;
	cin >> t;
	while(t--) solve();
}
