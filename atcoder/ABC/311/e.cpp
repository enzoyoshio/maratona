#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int h, w, n;
	cin >> h >> w >> n;
	vector<vector<int>> grid(h, vector<int>(w));

	for(int i = 0; i < n; i++) {
		int a, b; cin >> a >> b; a--, b--;
		grid[a][b] = 1;
	}
	auto psum = grid;

	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			if(i-1 >= 0) psum[i][j] += psum[i-1][j];
			if(j-1 >= 0) psum[i][j] += psum[i][j-1];
			if(i-1 >= 0 && j-1 >= 0) psum[i][j] -= psum[i-1][j-1];
		}
	}

	int ans = 0;

	auto query = [&](int x1, int y1, int x2, int y2) {
		return  psum[x2][y2] 
			- (y1 -1 >= 0 ? psum[x2][y1-1] : 0) 
			- (x1 -1 >= 0 ? psum[x1-1][y2] : 0)
			+ (x1 && y1 ? psum[x1-1][y1-1] : 0);

	};

	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			if(grid[i][j]) continue;

			int bl = 0, br = max(w, h)-1, bans = -1;

			while(bl <= br) {
				int bm = (bl+br)/2;
				
				if(i+bm >= h || j+bm >= w || query(i, j, i+bm, j+bm)) br = bm-1;
				else bans = bm, bl = bm + 1;

			}

//			cout << i << ' ' << j << ' ' << bans << endl;

			ans += bans+1;
		}
	}

	cout << ans << endl;
}
