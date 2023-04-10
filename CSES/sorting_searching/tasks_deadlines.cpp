#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	vector<pair<ll,ll>> v(n);
	for(auto& [a, b]: v)
		cin >> a >> b;

	ll time = 0;
	ll ans = 0;
	sort(v.begin(), v.end());

	for(auto [takes, endT]: v) {
		time += takes;
		ans += endT-time;
	}
	cout << ans << endl;
}
