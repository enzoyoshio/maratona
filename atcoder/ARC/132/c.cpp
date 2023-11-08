#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MOD = 998244353;

int n, d, used = 0;
vector<int> v;
vector<vector<int>> dp;

int add(int a, int b) {
	a += b;
	if(a >= MOD) a -= MOD;
	if(a < 0) a += MOD;
	return a;
}

bool get(int bit, int idx) {
	return (bit >> idx) & 1;
}

int f(int idx, int bit) {

	if(idx >= n)
		return 1;
	
	if(v[idx] != -1) {
		return f(idx+1, bit >> 1);
	}

	for(int i = 0; i < 2*d+1; i++) {
		if(idx-d+i < 0 || get(used, idx-d+i)) bit |= (1 << i);
	}

	auto& ans = dp[idx][bit];
	if(~ans) return ans;
	ans = 0;

	for(int i = 0; i < 2*d+1 && idx-d+i < n; i++) {
		if(get(bit, i)) continue;
		bit ^= (1 << i);
		if(get(bit, 0)) {
			/*
			cout << "\n\nstate\n";
			cout << idx << ' ' << bitset<10>(bit).to_string() << endl;
			cout << "using " << i << ' ' << idx-d+i << endl;
			*/
			ans = add(ans, f(idx+1, bit >> 1));
		}
		bit ^= (1 << i);
	}


	return ans;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	cin >> n >> d;
	v.resize(n);

	for(auto& it: v) {
		cin >> it;
		if(~it) {
			it--;
			used |= (1 << it);
		}
	}

	// basicaly copied editorial solution
	// I dont understand why my solution does not work
	// its the same idea as the editorial

	dp.resize(n+1, vector<int>(1 << (2*d+1), 0));

	/*
	// here I say that the first D guys are free to choose?
	dp[0][(1 << (d+1)) -1] = 1;
	for(int i = 0; i < n; i++) {
		for(int set = 1; set < (1 << (2*d+1)); set += 2) {
			const int newSet = set >> 1;
			for(int j = 0; j < d+d+1; j++) {
				if(v[i] >= 0 && v[i] != i + j - d)
					continue;
				if(~newSet >> j & 1)
					dp[i+1][newSet | 1 << j] = 
					add(dp[i+1][newSet | 1 << j],
							dp[i][set]);
			}
		}
	}	

	cout << dp[n][(1 << (d+1)) -1] << endl;
	return 0;
	*/

	/*
	int to = 0;
	for(int i = 0; i < 2*d+1; i++) {
		if(i < d) to |= 1 << i;
	}
	for(int i = 0; i < d; i++) {
		if(~v[i]) {
			to |= (1 << (v[i]-d));
		}
	}
	if(~v[0]) to |= 1 << v[0];
	cout << f(0, to) << endl;
	*/
	cout << f(0, 0) << endl;
}
