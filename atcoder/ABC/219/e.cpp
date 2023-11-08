#include <bits/stdc++.h>

using namespace std;
#define int long long
#define sz(x) (int)size(x)

struct DSU {
	vector<int> pai;
	int n;

	DSU(int _n) {
		n = _n;
		pai.resize(n);
		iota(begin(pai), end(pai), 0LL);
	}

	int find(int x) { return x == pai[x] ? x : pai[x] = find(pai[x]);}

	void join(int x, int y) {
		x = find(x);
		y = find(y);
		if(x == y) return;
		pai[y] = x;
	}
};

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	vector<int> cabana(16);
	for(auto& it: cabana) cin >> it;

	auto is = [](int id, int bitmask) {
		return ((bitmask >> id) & 1) != 0;
	};

	auto bound = [](int x) {
		return 0 <= x && x < 16;
	};

	int ans = 0;
	for(int bitmask = 1; bitmask < 1 << 16; bitmask++) {
		DSU d(20);

		bool can = true;
		for(int i = 0; can && i < 16; i++) {

			if(bound(i+4) && is(i, bitmask) == is(i+4, bitmask)) d.join(i, i+4);
			if(bound(i-4) && is(i, bitmask) == is(i-4, bitmask)) d.join(i, i-4);
			if(bound(i+1) && (i+1)%4 && is(i, bitmask) == is(i+1, bitmask)) d.join(i, i+1);
			if(bound(i-1) && (i)%4 && is(i, bitmask) == is(i-1, bitmask)) d.join(i, i-1);

			if(!is(i, bitmask)) {
				if(!bound(i-4) || !bound(i+4) || (i+1)%4 == 0 || i%4 == 0) d.join(i, 16);
			}

			if(cabana[i] && !is(i, bitmask)) can = false;

		}

		if(!can) continue;

		set<int> pais;
		for(int i = 0; i <= 16; i++)
			pais.insert(d.find(i));

		if(sz(pais) <= 2) {
			ans++;
			continue;

			cout << "\n\nACHEI UMA REPOSTA\n";
			for(int i = 0; i < 16; i++) {
				cout << is(i, bitmask) << ' ';
				if((i+1)%4 == 0) cout << endl;
			}

			cout << "pais -> ";
			for(auto it: pais) cout << it << ' ' ;
			cout << endl;
		}
	}
	cout << ans << endl;
}
