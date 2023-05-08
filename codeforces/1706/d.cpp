#include <bits/stdc++.h>

using namespace std;

const int MAXN = 4e3;
int n, k;
vector<int> v(MAXN);

bool check(int target, int start) {

	cout << "checker ------------------------------------->\n";
	cout << "testando " << target << ' ' << start << endl;

	for(int i = 0; i < n; i++) {
		int el = (v[i])/start;
		int up = (v[i]+start-1)/start;

		cout << "------------------------->\n";
		cout << " i = " << i << endl;
		cout << " v[i] = " << v[i] << endl;
		cout << " el = " << el << endl;
		cout << " up = " << up << endl;
		if((el*v[i] > start + target && up*v[i] > start+target) || (el > k && up > k) || (el*v[i] < start && up*v[i] < start))
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

		int mx = *max_element(begin(v), begin(v) + n);
		int mn = *min_element(begin(v), begin(v) + n);

		if(k*2 > mx) {
			cout << 0 << endl;
			continue;
		}

		int l = 1, r = mx-mn, ans = mx-mn;

		while(l <= r) {
			int mid = (l + r) >> 1;

			bool can = false;

			for(int i = 1; i+mid <= mx; i++)
				can |= check(mid, i);

			if(can)
				ans = mid, r = mid-1;
			else
				l = mid+1;
		}

		cout << ans << endl;
	}
}
