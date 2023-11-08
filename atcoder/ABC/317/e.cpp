#include <bits/stdc++.h>

using namespace std;

using ii = pair<int,int>;
using iii = array<int,3>;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<string> grid(n);
	for(auto& it: grid) cin >> it;

	ii start(-1, -1), fim;

//	map<ii, set<int>> lines, columns;
	vector<vector<vector<int>>> lines(max(n, m), vector<vector<int>>(4));
	auto columns = lines;
	vector<vector<int>> psum(n, vector<int>(m));

	vector<int> to(1000);
	to['v'] = 0;
	to['^'] = 1;
	to['<'] = 2;
	to['>'] = 3;
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(grid[i][j] == 'v') {
				lines[i][to['v']].push_back(j);
				columns[j][to['v']].push_back(i);
			}
			if(grid[i][j] == '^') {
				lines[i][to['^']].push_back(j);
				columns[j][to['^']].push_back(i);
			}
			if(grid[i][j] == '<') {
				lines[i][to['<']].push_back(j);
				columns[j][to['<']].push_back(i);

			}
			if(grid[i][j] == '>') {
				lines[i][to['>']].push_back(j);
				columns[j][to['>']].push_back(i);
			}

			if(grid[i][j] == 'S')
				start = {i, j};
			if(grid[i][j] == 'G')
				fim = {i, j}, grid[i][j] = '.';

			if(grid[i][j] == '.') {
				psum[i][j] = 1;
			}

			if(i-1 >= 0) psum[i][j] += psum[i-1][j];
			if(j-1 >= 0) psum[i][j] += psum[i][j-1];
			if(i-1 >= 0 && j-1 >= 0) psum[i][j] -= psum[i-1][j-1];
		}
	}

	for(auto& line: lines)
		for(auto& bost: line)
			sort(begin(bost), end(bost));
	for(auto& line: columns)
		for(auto& bost: line)
			sort(begin(bost), end(bost));


	auto bound = [&](int i, int j) {
		return 0 <= i && i < n && 0 <= j && j < m;
	};

	vector<ii> pos = {
		{0, 1},
		{0, -1},
		{1, 0},
		{-1, 0}
	};

	queue<ii> F;
	F.push(start);
	vector<vector<int>> dist(n, vector<int>(m, -1));
	dist[start.first][start.second] = 0;

		auto q = [&](int i, int j, int x, int y) {
			int ans = psum[x][y];
			if(i-1 >= 0) ans -= psum[i-1][y];
			if(j-1 >= 0) ans -= psum[x][j-1];
			if(i-1 >= 0 && j-1 >= 0) ans += psum[i-1][j-1];
			return ans;
		};


	auto check = [&](int fx, int fy, int tx, int ty) {
		int dirx = tx-fx, diry = ty - fy;

		if(dirx == 0) {
			auto pb = lower_bound(begin(columns[ty][to['^']]), end(columns[ty][to['^']]), tx);
			if(pb != columns[ty][to['^']].end()) {

				int x = q(tx, ty, *pb, ty);
				
				if(abs(x) == abs(tx-*pb)) return false;
			}
			auto pu = lower_bound(begin(columns[ty][to['v']]), end(columns[ty][to['v']]), tx);

			if(pu != columns[ty][to['v']].begin()) pu--;

			if(pu != columns[ty][to['v']].end()) {
				int x = q(*pu, ty, tx, ty);
				if(abs(x) == abs(tx-*pu)) return false;
			}
		}else {
			auto pb = lower_bound(begin(lines[tx][to['<']]), end(lines[tx][to['<']]), ty);
			if(pb != lines[tx][to['<']].end()) {

				int x = q(tx, ty, tx, *pb);
				//cout << " que merda " <<  x << endl;
				if(abs(x) == abs(ty-*pb)) return false;
			}
			auto pu = lower_bound(begin(lines[tx][to['>']]), end(lines[tx][to['>']]), ty);

			if(pu != lines[tx][to['>']].begin()) pu--;
			if(pu != lines[tx][to['>']].end() && *pu <= ty) {
				int x = q(tx, *pu, tx, ty);
				//cout << tx << ' ' << *pu << ' ' << tx << ' ' << fy << endl;
				//cout << " burro do caralho " << x << endl;
				if(abs(x) == abs(ty-*pu)) return false;
				//cout << "burtro pra caralhozn\n";
			}
		}
		return true;
	};

	while(F.size()) {
		auto [x, y] = F.front(); F.pop();

		for(auto [i, j]: pos) {
			i += x, j += y;

			if(bound(i, j) && dist[i][j] == -1 && (grid[i][j] == '.' || grid[i][j] == 'G') && check(x, y, i, j)) {
				dist[i][j] = dist[x][y]+1;
				F.emplace(i, j);
				//cout << "vis " << i << ' ' << j << endl;
			}
		}
	}

	/*
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			//cout << dist[i][j] << ' ';
		}
		//cout << endl;
	}
	*/

	cout << dist[fim.first][fim.second] << endl;
}
