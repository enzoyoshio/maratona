#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	for(auto& it: v)
		cin >> it;

	int ans = 0;
	for(int x = 1; x <= m; x++) {

		bool can = true;

		for(auto ak: v) {
			if((2*x - ak)%(2*ak)) can = false;
		}

		ans += can;
	}

	cout << ans << endl;
}
