#include <bits/stdc++.h>

using namespace std;

using iii = tuple<int,int,int>;

const int oo = 1e9;
const int neutro = 2*80*80;
int h, w;
vector<vector<int>> a, b;
vector<vector<vector<int>>> dp;
//map<iii, int> dp;

/*
int f(int i, int j, int soma) {
	
	if(i == h-1 && j == w-1) {
		return min(abs(soma + a[i][j] - b[i][j]), abs(soma + b[i][j] - a[i][j]));
	}

	if(dp.find(iii{i, j, soma}) != end(dp)) return dp[iii{i, j, soma}];

	int ans = oo;

	if(i+1 < h) ans = min({ans, f(i+1, j, soma + a[i][j] - b[i][j]), f(i+1, j, soma + b[i][j] - a[i][j])});
	if(j+1 < w) ans = min({ans, f(i, j+1, soma + a[i][j] - b[i][j]), f(i, j+1, soma + b[i][j] - a[i][j])});

	return dp[iii{i, j, soma}] = ans;
}
*/

int main() {
	cin.tie(0)->sync_with_stdio(false);

	cin >> h >> w;
	a.resize(h, vector<int>(w));
	b = a;
	dp.resize(h, vector<vector<int>>(w, vector<int>(4*80*80)));
	for(auto& line: a)
		for(auto& it: line)
			cin >> it;
	for(auto& line: b)
		for(auto& it: line)
			cin >> it;

	for(int i = h-1; i >= 0; i--) {
		for(int j = w-1; j >= 0; j--) {
			for(int soma = 0; soma < 2*neutro; soma++) {
				if(i == h-1 && j == w-1) {
					dp[h-1][w-1][soma] = min(abs(soma + a[h-1][w-1] - b[h-1][w-1] - neutro), abs(soma + b[h-1][w-1] - a[h-1][w-1] - neutro));
					continue;
				}
				auto& ans = dp[i][j][soma];
				dp[i][j][soma] = oo;
				if(i+1 < h) ans = min({ans, dp[i+1][j][soma + a[i][j] - b[i][j]], dp[i+1][j][soma + b[i][j] - a[i][j]]});
				if(j+1 < w) ans = min({ans, dp[i][j+1][soma + a[i][j] - b[i][j]], dp[i][j+1][soma + b[i][j] - a[i][j]]});
			}
		}
	}

	cout << dp[0][0][neutro] << endl;
}
