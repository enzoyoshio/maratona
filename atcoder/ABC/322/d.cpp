#include <bits/stdc++.h>

using namespace std;
#define int long long

void rotate(vector<string>& grid) {

	int n = grid.size();
	int m = grid[0].size();

	vector<string> red(m, string(n));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			ret[j][n-i-1] = grid[i][j];	
		}	
	}	
	grid = ret;
}

bool testa(vector<vector<string>>& mat) {

	for(int i = 0; i < 1 << 16; i++) {

	} 	
	return true;
}

vector<string> red(vector<string> redu) {
	while(true) {
		bool stop = false;
		for(int i = 0; i < 4; i++) {
		       if(redu[0][i] == '#')
		       		stop = true;	       
		}
		if(stop) break;
		for(int i = 0; i < 4; i++) {
			for(int j = 0; j < 4; j++) {
				if(i == 3) redu[i][j] = '.';
				else redu[i][j] = redu[i+1][j];
			}	
		}
	}	

	while(true) {
		bool stop = false;
		for(int i = 0; i < 4; i++) {
		       if(redu[i][0] == '#')
		       		stop = true;	       
		}
		if(stop) break;
		for(int j = 0; j < 4; j++) {
			for(int i = 0; i < 4; i++) {
				if(j == 3) redu[i][j] = '.';
				else redu[i][j] = redu[i][j+1];
			}	
		}
	}	

	int mx = 0;
	for(int i = 0; i < 4; i++) {
		while(redu[i].size() && redu[i].back() == '.')
			redu[i].pop_back();
		mx = max(mx, (int)redu[i].size());
	}

	while(redu.size() && redu.back() == "") redu.pop_back();

	for(int i = 0; i < redu.size(); i++) {
		while(redu[i].size() < mx) redu[i].push_back('.');
	}
	return redu;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	vector mat(3, vector<string>(4));

	for(auto& grid: mat)
		for(auto& line: grid)
			cin >> line;

	int qt = 0;
	for(auto grid: mat)
		for(auto line: grid)
			for(auto ch: line)
				qt += ch == '#';

	if(qt != 16) return cout << "No\n", 0;

	vector reduced(3, vector<string>());
	for(int i = 0; i < 3; i++) {
		reduced[i] = red(mat[i]);
	}

	cout << "No\n";
}
