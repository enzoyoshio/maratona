#include <bits/stdc++.h>

using namespace std;

int h, w;
vector<vector<int>> grid;

int pos(int i, int j, set<int> rep = {}) {

	if(i < 0 || i >= h || j < 0 || j >= w) return 0;

	if(i == h-1 && j == w-1) {
		rep.insert(grid[i][j]);
		return (int)rep.size() == h+w-1;
	}

	bool has = rep.find(grid[i][j]) != rep.end();

	if(has) return 0;

	rep.insert(grid[i][j]);
	int ans = pos(i+1, j, rep) + pos(i, j+1, rep);
	rep.erase(grid[i][j]);

	return ans;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	cin >> h >> w;
	grid.assign(h, vector<int>(w));
	for(auto& line: grid)
		for(auto& el: line)
			cin >> el;

	cout << pos(0, 0) << endl;
}
