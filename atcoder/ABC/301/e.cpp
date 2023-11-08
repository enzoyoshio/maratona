#include <bits/stdc++.h>

using namespace std;
#define int long long

#define db(x) cerr << "[ " << #x << " = " << x << " ]\n"

const int oo = 1e18;

vector<vector<int>> dist;

vector<vector<int>> tab;

#define db(x) cerr << "[ " << #x << " = " << x << " ]\n"

// dp to calculate minimum number of steps to reach goal
int dp(int idx, int bitmask) {

	// se eu cheguei no ultimo cara
	if(__builtin_popcountll(bitmask) == 0) {
		return dist[idx][1];
	}

	auto& cost = tab[idx][bitmask];
	if(~cost) return cost;
	cost = oo;

	for(int i = 0; i < dist.size(); i++) {
		if(bitmask & (1 << i)) {
			int dg = dp(i, bitmask ^ (1 << i));
			cost = min(cost, dist[idx][i] + dg);
		}
	}

	return cost;
}

signed main() {
//	cin.tie(0)->sync_with_stdio(false);

	int h, w, t;
	cin >> h >> w >> t;

	vector<string> grid(h);
	for(auto& it: grid) cin >> it;

	pair<int,int> s, g;
	vector<pair<int,int>> candy;
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			if(grid[i][j] == 'S') s = {i, j};
			else if(grid[i][j] == 'G') g = {i, j};
			else if(grid[i][j] == 'o') candy.emplace_back(i, j);
		}
	}

	candy.emplace_back(g);
	candy.emplace_back(s);

	reverse(begin(candy), end(candy));

	/*
	int c = 0;
	for(auto [x, y]: candy) {
		cout << "------------ candy ---------\n";
		db(x), db(y);
		db(c++);
	}
	*/

	vector<pair<int,int>> lado = {
		{0, 1},
		{0, -1},
		{1, 0},
		{-1, 0},	
	};

	auto bounded = [&](int i, int j) {
		return 0 <= i && i < h && 0 <= j && j < w;
	};

	dist.resize(candy.size(), vector<int>(candy.size(), oo));
	for(int i = 0; i < candy.size(); i++) {
		auto [l, m] = candy[i];
		vector<vector<int>> dist2(h, vector<int>(w, oo));
		dist2[l][m] = 0;
		queue<pair<int,int>> q;
		q.push(candy[i]);
		while(q.size()) {
			auto [x, y] = q.front(); q.pop();

			for(auto [a, b]: lado) {
				a += x, b += y;
				if(bounded(a, b) && dist2[a][b] == oo && grid[a][b] != '#') {
					dist2[a][b] = dist2[x][y] + 1;
					q.emplace(a, b);
				}
			}	
		}
		for(int j = 0; j < candy.size(); j++)
			dist[i][j] = dist2[candy[j].first][candy[j].second];
	}

	tab.resize(20, vector<int>(1 << 20, -1));
	int mx = -1;
	for(int i = 0; i < (1 << (dist.size())); i++) {
		if(i & 1) continue;
		if(i & 2) continue;
		if(i & 3) continue;

		if(dp(0, i) <= t) {
			mx = max(mx, (int)__builtin_popcountll(i));
		}
	}
	cout << mx << endl;
}
