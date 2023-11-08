#include <bits/stdc++.h>

using namespace std;
#define int long long

using iiii = array<int,4>;
using iii = array<int,3>;
using ii = pair<int,int>;

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t; while(t--) {
		int n; cin >> n;
		vector<iiii> v(n);
		for(auto& [l, r, a, b]: v)
			cin >> l >> r >> a >> b;

		// we keep
		// (a, b, furthest L to left)
		set<iii> s;

		auto in = [&](int aa, int bb, int cc) {
			return aa <= cc && cc <= bb;
		};

		auto add = [&](int Lbig, int Rbig,
			       int Abig, int Bbig) {

			if(s.empty()) {
				s.emplace(Abig, Bbig, Lbig);
			}


		};

		for(auto [l, r, a, b]: v) {
			add(l, r, a, b);
		}

		/*
		cout << "after merge all\n";
		for(auto [x, y]: s)
			cout << x << ' ' << y << endl;
			*/

		int q;
		cin >> q;
		for(int i = 0; i < q; i++) {
			int a;
			cin >> a;

			auto ub = s.upper_bound({a, 0});

			if(ub == begin(s)) {
				if(ub->first == a) cout << ub->second << ' ';
				else
					cout << a << ' ';
			}
			else {
				ub--;
				if(ub->second < a) cout << a << ' ';
				else cout << ub->second << ' ';
			}
		}
		cout << '\n';
	}
}
