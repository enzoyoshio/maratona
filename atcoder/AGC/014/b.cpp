#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	for(int i = 0; i < m; i++) {
		int a, b; cin >> a >> b; a--, b--;
		v[a]++, v[b]++;
	}

	for(int i = 0; i < n; i++) {
		if(v[i]%2) return cout << "NO\n", 0;
	}

	cout << "YES\n";
}
