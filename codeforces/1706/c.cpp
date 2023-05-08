#include <bits/stdc++.h>

using namespace std;

#define int long long

const int oo = 1e18;

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t; while(t--) {
		int n;
		cin >> n;
		vector<int> v(n);
		for(auto& el: v)
			cin >> el;

		if(n%2) {
			int ans = 0;
			for(int i = 1; i < n; i+=2) {
				if(v[i] > v[i-1] && v[i] > v[i+1]) continue;

				ans += max(v[i-1], v[i+1]) - v[i] + 1;
			}
			cout << ans << endl;
			continue;
		}

		vector<int> psum(n), ssum(n);

		for(int i = 1; i+1 < n; i++) {
			if(v[i] > v[i-1] && v[i] > v[i+1]) continue;
			psum[i] = max(v[i-1], v[i+1]) - v[i] + 1;
		}

		for(int i = 1; i < n; i++)
			if(i-2 >= 0)
				psum[i] += psum[i-2];

		for(int i = n-2; i; i--) {
			if(v[i] > v[i-1] && v[i] > v[i+1]) continue;
			ssum[i] = max(v[i-1], v[i+1]) - v[i] +1;
		}

		for(int i = n-2; i >= 0; i--) {
			if(i+2 < n)
				ssum[i] += ssum[i+2];
		}

		/*
		for(int i = 0; i < n; i++) {
			cout << psum[i] << ' ';
		}
		cout << endl;

		for(int i = 0; i < n; i++)
			cout << ssum[i] << ' ';
		cout << endl;
		*/

		int ans = oo;
		for(int i = 1; i+1 < n; i+=2) {
			int left = (v[i] > v[i-1] && v[i] > v[i+1] ? 0 : max(v[i-1], v[i+1]) - v[i] + 1);

			left += (i-2 >= 0 ? psum[i-2] : 0);

			if(i+3 < n)
				left += min(ssum[i+2], ssum[i+3]);
			else if(i+2 < n)
				left += ssum[i+2];

			int j = i+1;
			int right = (j+1 < n && v[j] > v[j-1] && v[j] > v[j+1] ? 0 : max(v[j-1], v[j+1]) - v[j] + 1);

			right += (j+2 < n ? ssum[j+2] : 0);

			if(j - 3 >= 0)
				right += min(psum[j-2], psum[j-3]);
			else if(j - 2 >= 0)
				right += psum[j-2];

			/*
			cout << "i = " << i << endl;
			cout << "left = " << left << " right = " << right << endl;
			*/
			ans = min({ans, left, right});
		}

		cout << ans << endl;
	}
}
