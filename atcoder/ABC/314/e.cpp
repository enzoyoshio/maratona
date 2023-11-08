#include <bits/stdc++.h>

using namespace std;

int n, m, len;
vector<int> cost;
vector<vector<int>> points;
vector<double> dp;
vector<bool> foi;

double f(int idx) {
	
	if(idx <= 0) return 0;

	if(foi[idx]) return dp[idx];
	foi[idx] = true;

	auto& ans = dp[idx];
	ans = -1;

	for(int i = 0; i < n; i++) {
		int t = points[i].size();
		double acum = 0;
		int zero = 0;
		for(int j = 0; j < t; j++) {
			if(points[i][j] == 0) zero++;
			else
				acum += f(idx-points[i][j]);
		}

		if(zero) {
			acum = (acum)/(double)(t) + cost[i];
			acum *= t;
			acum /= (t-zero);
		}else {
			acum = acum/(double)t + cost[i];
		}
		if(ans < 0) ans = acum;
		ans = min(ans, acum);
	}

	return ans;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	cin >> n >> m;
	cost.resize(n);
	points.resize(n);
	dp.resize(m+2);
	foi.resize(m+2, false);

	len = 0;
	for(int i = 0; i < n; i++) {
		cin >> cost[i];
		int t; cin >> t;
		len += t;
		for(int j = 0; j < t; j++) {
			int a; cin >> a; points[i].push_back(a);
		}
	}

	cout << fixed << setprecision(15);
	cout << f(m) << endl;
}
