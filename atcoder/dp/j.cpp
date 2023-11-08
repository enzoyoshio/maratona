#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> v(n);
	int qt1 = 0, qt2 = 0, qt3 = 0;
	for(auto& it: v) {
		cin >> it;
		qt1 += it == 1;
		qt2 += it == 2;
		qt3 += it == 3;
	}
	int sum = qt1 + qt2 + qt3;

	vector dp(n+3, vector<vector<double>>(n+3, vector<double>(n+3)));

	for(int q3 = 0; q3 <= n; q3++) {
		for(int q2 = 0; q2 + q3 <= n; q2++) {
			for(int q1 = 0; q1 + q2 + q3 <= n; q1++) {
				if(q1 + q2 + q3 == 0) continue;

				auto& ans = dp[q1][q2][q3];
				ans = n;	
				if(q1)
					ans += q1 * dp[q1-1][q2][q3];
				if(q2)
					ans += q2 * dp[q1+1][q2-1][q3];
				if(q3)
					ans += q3 * dp[q1][q2+1][q3-1];
				ans /= (q1+q2+q3);
			}
		}
	}
	cout << fixed << setprecision(20);
	cout << dp[qt1][qt2][qt3] << endl;
}
