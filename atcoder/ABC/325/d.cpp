#include <bits/stdc++.h>

#define int long long
using namespace std;

using ll = long long;
using ii = pair<ll,ll>;
using iii = array<ll, 3>;

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	vector<iii> v(n);
	set<ii> livre;
	for(int i = 0; i < n; i++) {
		ll a, b;
		cin >> a >> b;
		v[i] = {a+b, a, i};
		livre.emplace(a, a);
		livre.emplace(a+b, a+b);
	}

	sort(begin(v), end(v));
	vector<bool> proc(n, false);
	
	/*
	cout << "\n\ntodos os ranges\n";
	for(auto [a, b]: livre) cout << a << ' ' << b << endl;
	*/

	for(auto [end_time, start, id]: v) {
		auto l = livre.lower_bound({start, -1});

		if(begin(livre) != l && prev(l)->second >= start) {
			l = prev(l);
		}

		if(l == end(livre)) continue;

		if(l->second > end_time) continue;

		auto nx = next(l);

		proc[id] = true;
		/*
		cout << endl << endl;
		cout << "range of cur " << start << ' ' << end_time << endl;
		cout << "id of cur " << id << endl;
		cout << "range found that is free " << l->first << ' ' << l->second << endl;
		*/
		
		auto [l1, r1] = *l;
		livre.erase(l);

		while(nx != end(livre)) {
			auto [l2, r2] = *nx;

			if(l2 != r1+1) {
				break;
			}

			r1 = r2-1;
			nx = livre.erase(nx);
			break;
		}

		livre.emplace(l1, r1+1);
		
		/*
		cout << "\n\ntodos os ranges\n";
		for(auto [a, b]: livre) cout << a << ' ' << b << endl;
		*/
	}
	cout << accumulate(begin(proc), end(proc), 0) << endl;
}
