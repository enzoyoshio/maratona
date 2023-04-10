#include <bits/stdc++.h>

using namespace std;

const int oo = 1e8;
const int MAXN = 2e5 + 98;
int n; string s, t;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int test; cin >> test; while(test--) {
		cin >> n >> s >> t;

		if(s[0] != t[0] || s.back() != t.back()) {
			cout << -1 << endl;
			continue;
		}

		vector<int> pos[2];
		for(int i = 0; i < n; i++)
			pos[s[i]-'0'].push_back(i);

		int cur = s[1]-'0', ans = 0;
		for(int i = 1; i < n-1; i++) {
			// se o s[i] == t[i]
			// continue pro prox
			if(cur == t[i]-'0') {
				cur = s[i+1]-'0';
				continue;
			}

			if(s[i-1] != s[i+1]) {
				ans++;
				s[i] = '0' + !(s[i]-'0');
				cur = s[i+1]-'0';
			}else {
			}	
		}
		cout << ans << endl;
	}
}
