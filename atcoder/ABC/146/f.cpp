#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5;
const int oo = 1e9;
int n, m;
vector<pair<int,int>> st(4*MAXN);
string s;

void build(int sti=1, int stl=0, int str=n) {
	if(stl == str) {
		st[sti] = make_pair(oo, stl);
		return;
	}

	int mid = (stl + str) >> 1, e = sti << 1, d = (sti << 1) + 1;

	build(e, stl, mid);
	build(d, mid+1, str);

	st[sti] = min(st[e], st[d]);
}

void update(int idx, int val, int sti=1, int stl=0, int str=n) {
	if(str < idx || stl > idx) return;

	if(stl == str) {
		st[sti] = make_pair(val, idx);
		return;
	}

	int mid = (stl+str) >> 1, e = sti << 1, d = (sti << 1) + 1;

	update(idx, val, e, stl, mid);
	update(idx, val, d, mid+1, str);

	st[sti] = min(st[e], st[d]);
}

pair<int,int> query(int A, int B, int sti=1, int stl=0, int str=n) {
	if(A > str || B < stl) return {oo, oo};

	if(A <= stl && str <= B) return st[sti];

	int mid = (stl + str) >> 1, e = sti << 1, d = (sti << 1) + 1;

	return min(query(A, B, e, stl, mid), query(A, B, d, mid+1, str));
}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	cin >> n >> m >> s;

	build();
	update(n, 0);

	vector<int> nx(n+1, -1);
	for(int i = n-1; i >= 0; i--) {
		if(s[i] == '1') continue;

		auto [val, idx] = query(i+1, min(i+m, n));

		if(val == oo) continue;

		update(i, val+1);
		nx[i] = idx-i;
	}

	if(nx[0] == -1) return cout << -1 << endl, 0;
	int cur = 0;

	while(~nx[cur]) {
		cout << nx[cur] << ' ';
		cur += nx[cur];
	}

	cout << endl;
}
