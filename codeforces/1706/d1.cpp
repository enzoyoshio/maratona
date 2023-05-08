#include <bits/stdc++.h>

using namespace std;

const int MAXN = 4e3;
int n, k; 
vector<int> v(MAXN);
vector<vector<int>> values(MAXN);

bool check(int range, int start) {

	for(int i = 0; i < n; i++) {

		auto p = lower_bound(begin(values[i]), end(values[i]), start);

		if(p == end(values[i]) || *p > start+range)
			return false;
	}

	return true;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t; while(t--) {
		cin >> n >> k;
		for(int i = 0; i < n; i++)
			cin >> v[i];
		
		int mx = *max_element(begin(v), end(v)), mn = *min_element(begin(v), end(v));

		if(k*2 > *max_element(begin(v), end(v))) {
			cout << 0 << endl;
			continue;
		}

		for(int i = 0; i < n; i++)
			values[i].clear();

		for(int i = 0; i < n; i++) {
			for(int j = 1; j <= k; j++) {
				if(values[i].empty() || values[i].back() != v[i]/j)
					values[i].push_back(v[i]/j);
			}
			reverse(begin(values[i]), end(values[i]));
		}

		int l = 0, r = mx-mn, ans = mx-mn;

		while(l <= r) {
			int mid = (l + r) >> 1;

			bool can = false;

			for(int i = 0; i+mid <= mx; i++) {
				can |= check(mid,i); 
			}

			if(can) ans = mid, r = mid-1;
			else l = mid+1;
		}

		cout << ans << endl;
	}

}
