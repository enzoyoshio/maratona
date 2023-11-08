#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<pair<int,int>> v(n);
	for(auto& [a, b]: v) cin >> a >> b;

	int ans = 0;
	for(int hora = 0; hora < 24; hora++) {

		int qt = 0;
		for(int i = 0; i < n; i++) {
			int t = v[i].second + hora;
			t %= 24;
			if(t >= 9 && t <= 17) qt+=v[i].first;
		}
		ans = max(ans, qt);
	}
	cout << ans << endl;
}
