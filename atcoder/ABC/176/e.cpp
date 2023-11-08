#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int h, w, m; cin >> h >> w >> m;

	vector<pair<int,int>> hs(h, make_pair(0, 0)), ws(w, make_pair(0, 0));

	for(int i = 0; i < h; i++) hs[i].second = i;
	for(int i = 0; i < w; i++) ws[i].second = i;
	set<pair<int,int>> points;

	while(m--) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		hs[a].first++;
		ws[b].first++;
		points.emplace(a, b);
	}

	sort(hs.rbegin(), hs.rend());
	sort(ws.rbegin(), ws.rend());
	while(hs.size() && hs.back().first != hs[0].first) hs.pop_back();
	while(ws.size() && ws.back().first != ws[0].first) ws.pop_back();

	int ans = 0;
	int limN = hs.size();
	int limM = ws.size();

	if((long long)limN * (long long)limM > 3e8) limN = 1000, limM = 1000;

	for(int i = 0; i < limN; i++) {
		for(int j = 0; j < limM; j++) {
			int cur = hs[i].first + ws[j].first - (points.find(make_pair(hs[i].second, ws[j].second)) != points.end() ? 1 : 0);
			ans = max(ans, cur);
		}
	}

	cout << ans << endl;
}
