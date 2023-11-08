#include <bits/stdc++.h>

using namespace std;
#define int long long

const int oo = 1e18;

struct ST {
	vector<int> st;
	int n;

	ST(int n) : n(n), st(4*n, oo) {}

	int update(int x, int v, int sti, int stl, int str) {
		if(stl > x || str < x) return st[sti];

		if(stl == str) return st[sti] = v;

		int stm = (stl+str)/2, ste = 2*sti, std = 2*sti+1;

		return st[sti] = min(update(x, v, ste, stl, stm), update(x, v, std, stm+1, str));
	}
	int update(int x, int v) { return update(x, v, 1, 0, n-1);}

	int query(int L, int R, int sti, int stl, int str) {
		if(L > R) return oo;
		if(stl > R || L > str) return oo;

		if(L <= stl && str <= R) return st[sti];

		int stm = (stl+str)/2, ste = 2*sti, std = 2*sti+1;
		return min(query(L, R, ste, stl, stm), query(L, R, std, stm+1, str));
	}
	int query(int L, int R) { return query(L, R, 1, 0, n-1);}
};

int n;

vector<int> solveL(vector<int>& v) {
	vector<int> ans(n+10, oo);

	ST left(n+10), right(n+10);

	for(int i = 1; i <= n; i++) {
		int l = left.query(1, v[i]-1);
		int r = right.query(v[i]+1, n);

		ans[i] = min(ans[i], v[i] + i + l);
		ans[i] = min(ans[i], -v[i] + i + r);
		left.update(v[i], -v[i] - i);
		right.update(v[i], v[i] - i);
	}

	return ans;
}

vector<int> solveR(vector<int>& v) {
	vector<int> ans(n+10, oo);

	ST left(n+10), right(n+10);

	for(int i = n; i >= 1; i--) {
		int l = left.query(1, v[i]-1);
		int r = right.query(v[i]+1, n);

		ans[i] = min(ans[i], v[i] - i + l);
		ans[i] = min(ans[i], -v[i] - i + r);
		left.update(v[i], -v[i] + i);
		right.update(v[i], v[i] + i);
	}

	return ans;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	cin >> n;
	vector<int> v(n+10);
	for(int i = 1; i <= n; i++)
		cin >> v[i];

	auto d = solveL(v);
	auto d2 = solveR(v);

	for(int i = 1; i <= n; i++)
		cout << min(d[i], d2[i]) << ' ';
	cout << endl;
}
