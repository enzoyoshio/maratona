#include <bits/stdc++.h>

using namespace std;
#define int long long

using iii = array<int,3>;

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> v;

	vector<pair<int,int>> par(n);
	for(auto& [a, b]: par) {
		cin >> a >> b;
		v.push_back(a);
		v.push_back(b);
	}

	vector<int> delta(v.size() + 10);
	auto ord = v;
	sort(ord.begin(), ord.end());

	auto id = [&](int idx) {
		return lower_bound(begin(ord), end(ord), idx) - begin(ord);
	};

	for(auto [a, b]: par) {
		delta[id(a)]++;
		delta[id(b)+1]--;
	}

	for(int i = 1; i < v.size(); i++) {
		delta[i] += delta[i-1];
	}

	int maxi = 0;

	for(int i = 0; i < v.size(); i++) {
		if(delta[i] > delta[maxi])
			maxi = i;
	}

	int real = ord[maxi];

	vector<int> ans;
	for(int i = 0; i < par.size(); i++) {
		auto [a, b] = par[i];

		if(a <= real && real <= b) ans.push_back(i+1);
	}
	
	cout << ans.size() << endl;
	for(auto it: ans) cout << it << ' ';
	cout << endl;
}
