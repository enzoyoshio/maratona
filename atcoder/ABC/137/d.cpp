#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vector<pair<int,int>> v(n);
	for(auto& [a, b]: v) 
		cin >> a >> b;

	sort(v.begin(), v.end());

	int idx = 0, ans = 0;
	multiset<int> pesos;
	for(int dia = m; dia; dia--) {
		while(idx < n && v[idx].first <= m-dia+1) pesos.emplace(v[idx++].second);

		if(pesos.size()) {
			ans += *prev(pesos.end());
			pesos.erase(prev(pesos.end()));
		}
	}

	cout << ans << endl;
}
