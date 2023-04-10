#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9+7;

int mul(int a, int b) {
	return ((long long)a * (long long)b)%MOD;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t; while(t--) {
		int n; cin >> n;
		vector<int> v(n);
		for(auto& el: v)
			cin >> el;
		vector<int> pos(n);
		for(int i = 0; i < n; i++) {
			pos[v[i]] = i;
		}

		if(n <= 3) {
			cout << 1 << endl;
			continue;	
		}


		int l = min(pos[0], pos[1]), r = max(pos[0], pos[1]), ans = 1;

		for(int i = 2; i < n; i++) {
			if(l < pos[i] && pos[i] < r) {
				ans = mul(ans, (r-l+1)-i);
			}
			else 
				l = min(l, pos[i]), r = max(r, pos[i]);
		}
		cout << ans << endl;
	}
}
