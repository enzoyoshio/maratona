#include <bits/stdc++.h>

using namespace std;

bool check(string& s, int x) {
	map<string, vector<int>> pos;
	for(int i = 0; i+x <= (int)s.size(); i++)
		pos[s.substr(i, x)].push_back(i);
	for(auto [str, v]: pos)
		for(int i = 0; i < (int)v.size(); i++)
			if(lower_bound(v.begin(), v.end(), v[i]+x)  != v.end()) return true;
	return false;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n; string s;
	cin >> n >> s;

	int l = 1, r = n, ans = 0;

	for(int x = n; x; x--) {
		if(check(s, x)) return cout << x << endl, 0;
	}
	/*
	while(l <= r) {
		int mid = (l+r) >> 1;
		if(check(s, mid)) ans = mid, l = mid+1;
		else r = mid-1;
	}
	*/

	cout << ans << endl;
}
