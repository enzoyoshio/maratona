#include <bits/stdc++.h>

using namespace std;

using iii = tuple<int,int,int>;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<string> grid(n);

	for(auto& line: grid) cin >> line;

	vector<pair<int,int>> lado = {
		{0, 1},
		{0, -1},
		{-1, 0},
		{1, 0},
	};

	vector oposto{1, 0, 3, 2};

	vector<vector<vector<int>>> vis(n, vector<vector<int>>(m, vector<int>(4)));

	queue<iii> q;
	q.emplace(1, 1, 0);
	q.emplace(1, 1, 3);
	vis[1][1][0] = 1;
	vis[1][1][3] = 1;

	while(q.size()) {
		auto [i, j, dir] = q.front(); q.pop();
		auto [x, y] = lado[dir];
		x+=i, y += j;

		if(grid[x][y] != '#' && !vis[x][y][dir]) {
			vis[x][y][dir] = 1;
			q.emplace(x, y, dir);
		}else {

			int c = 0;
			for(auto [a, b]: lado) {
				a+=i, b += j;
				if(grid[a][b] != '#' && !vis[a][b][c]) {
					vis[a][b][c] = 1;
					q.emplace(a, b, c);	
				}
				c++;
			}
		}
	}

	int ans = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			ans += *max_element(begin(vis[i][j]), end(vis[i][j]));
		}
	}
	cout << ans << endl;
}
