#include <bits/stdc++.h>

using namespace std;
#define int long long

const int oo = 1e18;

int n, m;
vector<string> grid;

using ii = pair<int,int>;
using iii = array<int,3>;

void print(vector<vector<int>> dist) {
	cout << endl << endl;

	cout << "table dist\n";
	for(auto l: dist) {
		for(auto el: l) cout << el << ' ';
		cout << endl;
	}
}

vector<ii> lado = {
	{0, 1},
	{0, -1},
	{1, 0},
	{-1, 0}
};


vector<vector<int>> gen(int i, int j) {
	auto bound = [&](int x , int y) {
		return 0 <= x && x < n && 0 <= y && y < m;
	};

	vector<vector<int>> tdist(n+10, vector<int>(m+10, oo));

	priority_queue<iii, vector<iii>, greater<iii>> pq;
	pq.push({0, i, j});
	tdist[i][j] = 0;
	while(pq.size()) {
		auto [w, i, j] = pq.top(); pq.pop();

		if(w > tdist[i][j]) continue;

		for(auto [a, b]: lado) {
			a += i, b += j;

			if(bound(a, b)) {
				int add = 0;
				if(grid[a][b] == '.')
					add++;

				if(tdist[a][b] > w + add) {
					tdist[a][b] = w+add;
					pq.push({w+add, a, b});
				}
			}
		}
	}

	return tdist;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	cin >> n >> m;
	grid.resize(n);
	for(auto& l: grid)
		cin >> l;

	pair<int,int> tpos;
	vector<pair<int,int>> star;
	vector<vector<int>> tdist, stardist, star2;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(grid[i][j] == 'T')
				tdist = gen(i, j);
			if(grid[i][j] == '*') {
				if(stardist.empty())
					stardist = gen(i, j);
				else
					star2 = gen(i, j);
			}
		}
	}

	assert(!star2.empty());

	/*
	print(tdist);
	print(stardist);
	print(star2);
	*/

	int ans = oo;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			int tot = tdist[i][j] + stardist[i][j] + star2[i][j];
			if(grid[i][j] == '.') tot -= 2;

			/*
			if(tot == 3) {
				cout << "pos = " << i << ' ' << j << endl;
				cout << "cost = " << tot << endl;
			}
			*/

			ans = min(ans, tot);
		}
	}

	cout << ans << endl;
}
