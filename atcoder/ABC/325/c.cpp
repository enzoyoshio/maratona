#include <bits/stdc++.h>

using namespace std;

using ii = pair<int,int>;
int h, w;
vector<string> grid;
vector<vector<int>> value;

vector<ii> lado = {
	{0, 1},
	{0, -1},
	{1, 0},
	{-1, 0},
	{-1, -1},
	{-1, 1},
	{1, -1},
	{1, 1},
};

bool bounded(int i, int j) {
	return 0 <= i && i < h && 0 <= j && j < w;
}

void bfs(int i, int j, int c) {

	queue<ii> q;
	q.emplace(i, j);

	while(q.size()) {
		auto [a, b] = q.front(); q.pop();

		value[a][b] = c;

		for(auto [x, y] : lado) {
			x += a, y += b;
			if(bounded(x, y) && grid[x][y] == '#' &&
					value[x][y] == -1) {
				value[x][y] = c;
				q.emplace(x, y);
			}
		}
	}
}

int main() {
	cin >> h >> w;
	grid.resize(h);
	value.resize(h, vector<int>(w, -1));

	for(auto& it: grid) cin >> it;

	int c = 0;

	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			if(value[i][j] == -1 && grid[i][j] == '#') {
				bfs(i, j, c++);
			}
		}
	}

	cout << c << endl;
}
