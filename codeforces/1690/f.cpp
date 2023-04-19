#include <bits/stdc++.h>

using namespace std;

#define int long long

int check(int idx, string& s, vector<int>& v, string& ori, vector<bool>& vis, int& tam) {

	int start = idx;
	vis[start] = 1;
	idx = v[idx];
	char leva = s[start];
	tam = 1;

	while(idx != start) {
		vis[idx] = 1;
		tam++;
		/*
		cout << start << endl;
		cout << idx << ' ' << v[idx] << endl;;
		*/
		char save = s[idx];
		s[idx] = leva;
		leva = save;
		idx = v[idx];
	}

	s[start] = leva;

	/*
	cout << s << endl;
	cout << ori << endl;
	*/
	return ori != s;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t; while(t--) {
		int n; string s, ori;
		cin >> n >> s;
		ori = s;
		vector<int> v(n);
		for(auto& it: v)
			cin >> it, it--;

		int ans = 1;

		vector<bool> vis(n, false);

		for(int i = 0; i < n; i++) {
			if(vis[i]) continue;

			int cur = 0;
			int tam = 0;
			//check(i, s, v, ori, vis);
			while(cur++, check(i, s, v, ori, vis, tam)) {}
			cur = min(tam, cur);
			ans = lcm(cur, ans); 
		}
		cout << ans << endl;
	}
}
