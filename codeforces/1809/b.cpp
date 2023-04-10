#include <bits/stdc++.h>

#define int long long

using namespace std;

void solve() {
	int n;
	cin >> n;
	if(n == 1) {
		cout << 0 << endl;
		return;
	}
	int x = 1;

	int l = 1, r = 1e9;

	while(l <= r) {
		int mid = (l+r)/2;

		int sum;
		if(mid%2) {
			sum = ((mid+1)/2) * ((mid+1)/2+1) - (mid+1)/2;
			sum *= 4;
		}else {
			sum = (((mid/2) * (mid/2+1))*4) + 1;
		}

		/*
		cout << "\n\ndbg\n";
		cout << "mid = " << mid << " sum =  " << sum << " n =  " << n << endl;
		cout << "x = " << x << endl;
		*/

		if(sum >= n) x = mid, r = mid-1;
		else l = mid+1;
	}

	cout << x << endl;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t=1;
	cin >> t;
	while(t--) solve();
}
