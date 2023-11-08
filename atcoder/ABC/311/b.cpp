#include <bits/stdc++.h>

using namespace std;

int main() {

	int n, m; cin >> n >> m;

	vector<int> can(m, 1);

	for(int i = 0; i < n; i++) {
		string s; cin >> s;
		for(int j = 0; j < m; j++)
			can[j] &= (s[j] == 'o');
	}

	int ans = 0;

	for(int i = 0; i < m; i++) {
		for(int j = i; j < m && can[j]; j++) {
			ans = max(ans, j-i+1);
		}
	}
	cout << ans << endl;
}
