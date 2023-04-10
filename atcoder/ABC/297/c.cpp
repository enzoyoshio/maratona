#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int h, w;
	cin >> h >> w;
	vector<string> grid(h);
	for(auto& line: grid) cin >> line;

	for(int i = 0; i < h; i++) {
		for(int j = 0; j+1 < w; j++) {
			if(grid[i][j] == 'T' && grid[i][j+1] == 'T')
				grid[i][j] = 'P',
				grid[i][j+1] = 'C';
		}
	}

	for(auto line: grid)
		cout << line << endl;
}
