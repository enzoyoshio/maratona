#include <bits/stdc++.h>

using namespace std;
#define int long long

const int oo = 1e18;

using iii = array<int,3>;

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, m, k;
	cin >> n >> m >> k;
	vector<int> room(n);
	for(auto& it: room) cin >> it;

	// keep track of room destiny/ length/ required key
	vector<unordered_map<int, vector<pair<int,int>>>> g(n);

	for(int i = 0; i < m; i++) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		a--, b--;
		g[a][d].push_back({b, c});
		g[b][d].push_back({a, c});
	}

	// dist to tell minimum distance to reach here
	// using some cartao
	map<pair<int,int>, int> dist;
	// pq stores current distance/ room/ key
	priority_queue<iii, vector<iii>, greater<iii>> pq;
	dist[{0, room[0]}] = 0;
	pq.push({0, 0, room[0]});

	int ans = oo;
	while(pq.size()) {
		auto [min_dist, cur_room, key] = pq.top(); pq.pop();

		if(dist[{cur_room, key}] < min_dist) continue;

		if(cur_room == n-1) {
			ans = min(ans, min_dist);
			continue;
		}

		if(g[cur_room].find(key) != g[cur_room].end()) {
			for(auto [nxt_room, nxt_dist]: g[cur_room][key]) {
				if(dist.find({nxt_room, key}) == dist.end() || dist[{nxt_room, key}] > min_dist + nxt_dist) {

					dist[{nxt_room, key}] = min_dist + nxt_dist;
					pq.push({dist[{nxt_room, key}], nxt_room, key});
				}
			}
		}

		auto key2 = room[cur_room];
		if(g[cur_room].find(key2) != g[cur_room].end()) {
			for(auto [nxt_room, nxt_dist]: g[cur_room][key2]) {
				if(dist.find({nxt_room, key2}) == dist.end() || dist[{nxt_room, key2}] > min_dist + nxt_dist) {

					dist[{nxt_room, key2}] = min_dist + nxt_dist;
					pq.push({dist[{nxt_room, key2}], nxt_room, key2});
				}
			}

		}
	}

	cout << (ans == oo ? -1 : ans) << endl;
}
