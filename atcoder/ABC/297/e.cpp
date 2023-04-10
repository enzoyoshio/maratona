#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for(auto& it: v) cin >> it;

	sort(v.begin(), v.end());

	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(0);

	set<int> ans, vis;
	vis.insert(0);

	while((int)ans.size() < k) {
		auto el = pq.top(); pq.pop();

		if(el) ans.insert(el);

		for(auto num: v) {
			if(vis.find(el + num) != vis.end()) continue;

			vis.insert(el + num);
			pq.push(el + num);
		}	
	}

	cout << *ans.rbegin() << endl;
}
