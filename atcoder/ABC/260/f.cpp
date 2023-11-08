#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int s, t, m;
	cin >> s >> t >> m;

	vector v(s, vector<int>());
	vector memo(t, vector<int>(t, -1));

	for(int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		a--, b--;
		b -= s;
		v[a].push_back(b);
	}

	for(int i = 0; i < s; i++) {
		for(int j = 0; j < v[i].size(); j++) {
			for(int k = j+1; k < v[i].size(); k++) {
				if(memo[v[i][j]][v[i][k]] != -1) {
					cout << i+1 << ' ';
					cout << v[i][j]+s+1 << ' ';
					cout << v[i][k]+s+1 << ' ';
					cout << memo[v[i][j]][v[i][k]]+1 << endl;
					return 0;
				}else memo[v[i][j]][v[i][k]] = i,
				      memo[v[i][k]][v[i][j]] = i;
			}
		}
	}
	cout << -1 << endl;
}
