#include <bits/stdc++.h>

using namespace std;
#define int long long

const int oo = 1e18;
using iii = array<int, 3>;

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, a, b, c;
	cin >> n >> a >> b >> c;
	vector d(n, vector<int>(n));
	for(auto& line: d)
		for(auto& it: line)
			cin >> it;

	vector dist(2, vector<int>(n, oo));

	// dist / type of transportation / idx
	priority_queue<iii, vector<iii>, greater<iii>> pq;
	dist[0][0] = 0;
	dist[1][0] = 0;

	pq.push({0, 0, 0});
	pq.push({0, 1, 0});

	while(pq.size()) {
		auto [di, type, idx] = pq.top(); pq.pop();

		if(dist[type][idx] < di) continue;

		for(int i = 0; i < n; i++) {
			if(!type && di + d[idx][i] * a  < dist[0][i]) {
				dist[0][i] = di + d[idx][i] * a;
				pq.push({dist[0][i], 0, i});
			}
	
			if(di + d[idx][i] * b + c < dist[1][i]) {
				dist[1][i] = di + d[idx][i] * b + c;
				pq.push({dist[1][i], 1, i});
			}
		}
	}

	cout << min(dist[1].back(), dist[0].back()) << endl;
}
