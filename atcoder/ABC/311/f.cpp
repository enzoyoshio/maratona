#include <bits/stdc++.h>

using namespace std;
#define int long long

#define db(x) cerr << "[ " << #x << " = " << x << " ]\n"

const int MOD = 998244353;

int add(int a, int b) { return (a+b)%MOD;}
int sub(int a, int b) { return ((a-b)%MOD + MOD)%MOD;}
int mul(int a, int b) { return (a*b)%MOD;}
int fexp(int b, int e=MOD-2) {
	if(e == 0) return 1LL;

	int x = fexp(b, e/2);
	x = mul(x, x);
	if(e%2) x = mul(b, x);
	return x;
}

int n, m;
vector<string> grid;
vector<vector<int>> dp;
vector<int> qt, limit;

int f(int diagonal, int black) {

	if(diagonal >= n+m-1) {
	//	cout << "fim\n";
	//	cout << diagonal << ' ' << black << endl;
		return 1;
	}

//	auto& ans = dp[diagonal][black];
//	if(~ans) return ans;
	int ans = 0;

	for(int b = black; b <= limit[diagonal]; b++) {
		ans = add(ans, f(diagonal + 1, max(b-(diagonal < m -1? 0 : 1), qt[diagonal+1])));
	}
	/*
	cout << "----------------- db --------------------\n";
	db(diagonal);
	db(black);
	db(ans);
	*/

	return ans;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	cin >> n >> m;
	grid.resize(n);
	qt.resize(2*max(n,m));
	limit.resize(2*max(n,m));
	dp.resize(2*max(n, m), vector<int>(2*max(n, m), 1));

	// reading stuff
	for(auto& line: grid) cin >> line;

	for(int i = 1; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(grid[i-1][j] == '#' || (j && grid[i-1][j-1] == '#')) grid[i][j] = '#';
		}
	}
	for(int i = 0; i < n; i++) {
		while(grid[i].size() < max(n, m)) grid[i] += '#';
	}
	string s = "";
	for(int i = 0; i < max(n, m); i++) s += '#';
	while(grid.size() < max(n, m)) {
		grid.push_back(s);
	}
	n = max(n, m); m = max(n, m);

	for(int i = size(grid)-1; i  >= 0; i--) {
		for(int j = size(grid)-1; j >= 0; j--) {
			limit[i-j+size(grid)-1]++;
			if(grid[i][j] == '#')
				qt[i-j+size(grid)-1]++;	
		}
	}
//	for(auto el: qt) cout << el << ' '; cout << endl;
//	for(auto el: limit) cout << el << ' '; cout << endl;

	auto psum = [&](int l, int r, int id) {
		if(r < l) return 0LL;
		if(l == 0) return dp[id][r];

		return sub(dp[id][r] , dp[id][l-1]);
	};

	/*
	for(int black = 0; black <= limit[d]; black++) {

		auto& ans = dp[d][black];
		ans = 0;

//			cout << "------------------- db ------------------\n";
//			db(d);
//			db(black);
		for(int b = black; b <= limit[d]; b++) {
//				cout << "                                  sub ------------\n";
//				db(b);
//				db(d+1);
//				db(b-(d < m-1 ? 0: 1));
//				db(qt[d+1]);
			ans = add(ans, dp[d+1][max(b-(d < max(n, m)-1 ? 0 : 1), qt[d+1])]);
		}

	}
	continue;
	*/


	for(int d = n+m-2; d >= 0; d--) {
		for(int black = limit[d]; black >= 0; black--) {
			auto& ans = dp[d][black];
			ans = 0;

			if(d >= n-1) {
				ans = add(ans, dp[d+1][max(black-1, qt[d+1])]);
			}else {
				ans = add(ans, dp[d+1][max(black, qt[d+1])]);
			}

			if(black != limit[d]) ans = add(ans, dp[d][black+1]);
		}

		
	}	

	cout << dp[0][qt[0]] << endl;
//	cout << f(0, qt[0]) << endl;
}
