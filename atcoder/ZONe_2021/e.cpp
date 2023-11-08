#include <bits/stdc++.h>

using namespace std;

const int oo = 1e9;
using iii = array<int, 3>;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int r, c;
	cin >> r >> c;

	vector a(r, vector<int>(c-1));
	vector b(r-1, vector<int>(c));

	for(auto& l: a)
		for(auto& el: l)
			cin >> el;
	for(auto& l: b)
		for(auto& el: l)
			cin >> el;

	vector dist(r, vector<int>(c, oo));

	dist[0][0] = 0;
	priority_queue<iii, vector<iii>, greater<iii>> pq;
	pq.push({0, 0, 0});

	while(pq.size()) {
		auto [d1, i, j] = pq.top(); pq.pop();

		if(d1 > dist[i][j]) continue;

		if(i+1 < r && dist[i+1][j] > d1 + b[i][j]) {
			dist[i+1][j] = d1 + b[i][j];
			pq.push({dist[i+1][j], i+1, j});
		}
		if(j+1 < c && dist[i][j+1] > d1 + a[i][j]) {
			dist[i][j+1] = d1 + a[i][j];
			pq.push({dist[i][j+1], i, j+1});
		}
		if(j-1 >= 0 && dist[i][j-1] > d1 + a[i][j-1]) {
			dist[i][j-1] = d1 + a[i][j-1];
			pq.push({dist[i][j-1], i, j-1});
		}

		for(int k = 0; k < i; k++) {
			if(dist[i-k-1][j] > d1 + k+2) {
				dist[i-k-1][j] = d1 + k+2;
				pq.push({dist[i-k-1][j], i-k-1, j});
			}
		}
	}
	cout << dist[r-1][c-1] << endl;
}
