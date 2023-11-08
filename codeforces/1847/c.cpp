#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t; while(t--) {
		int n; cin >> n;
		vector<int> v(n);
		for(auto& it: v) cin >> it;

		for(int x = (1 << 8) -1; x >= 0; x--) {
			bitset<256> found;
			found[x] = 1;

			int xorsum = 0;
			bool can = false;
			for(int i = 0; i < n; i++) {
				xorsum ^= v[i];
				if(found[xorsum]) {
					can = true;
					break;
				}
				found[x ^ xorsum] = 1;
			}

			if(can) {
				cout << x << endl;
				break;
			}
		}
	}
}
