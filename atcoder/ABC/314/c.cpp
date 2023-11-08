#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, m;
	string s;
	cin >> n >> m >> s;
	vector<int> cor(n);
	for(auto& it: cor) cin >> it, it--;

	string ans(n, 'a');

	vector<vector<int>> corpos(m);
	for(int i = 0; i < n; i++) {
		corpos[cor[i]].push_back(i);
	}

	for(int i = 0; i < m; i++) {
		for(int j = 0; j < corpos[i].size(); j++) {
			int sz = corpos[i].size();
			int idx = corpos[i][(j-1+sz)%sz];
			if(sz == 1) idx = corpos[i][0];
			ans[corpos[i][j]] = s[idx];
		}
	}
	cout << ans << endl;
}
