#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3e5;
int n, m;
vector<int> v(MAXN);
vector<pair<int,int>> st(4*MAXN);

void build(int sti=1, int stl=0, int str=n-1) {
	if(stl == str) {
		st[sti] = make_pair(v[stl], -str);
		return;
	}

	int mid = (stl+str) >> 1, e = sti << 1, d = (sti << 1) + 1;

	build(e, stl, mid);
	build(d, mid+1, str);

	st[sti] = max(st[e], st[d]);
}

void update(int id, int val, int sti=1, int stl=0, int str=n-1) {

	if(id > str || id < stl) return;

	if(stl == str) {
		st[sti] = make_pair(val, -id);
		return;
	}

	int mid = (stl + str) >> 1, e = sti << 1, d = (sti << 1) + 1;

	update(id, val, e, stl, mid);
	update(id, val, d, mid+1, str);

	st[sti] = max(st[e], st[d]);
}

pair<int,int> query(int val, int sti=1, int stl=0, int str=n-1) {

	if(stl == str) {
		if(st[sti].first < val) return make_pair(-1, -1);	
		return st[sti];
	}

	int mid = (stl + str) >> 1, e = sti << 1, d = (sti << 1) + 1;

	if(st[e].first >= val) {
		return query(val, e, stl, mid);	
	}else {
		return query(val, d, mid+1, str);
	}
}

pair<int,int> q(int A, int B, int sti=1, int stl=0, int str=n-1) {
	if(A > str || B < stl) return make_pair(-1, -1);

	if(A <= stl && str <= B) return st[sti];

	int mid = (stl+str) >> 1, e = sti << 1, d = (sti << 1) +1;

	return max(q(A, B, e, stl, mid), q(A, B, d, mid+1, str));
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	
	cin >> n >> m;

	for(int i = 0; i < n; i++) {
		cin >> v[i];
	}

	build();
//	for(int i = 0; i < n; i++) {
//		auto [a, b] = q(i, i);
//		cout << a << ' ' << b << endl;
//	}

	vector<int> ans;
	for(int i = 0; i < m; i++) {
		int qt; cin >> qt;

		auto [valor, pos] = query(qt);

//		cout << valor << ' ' << pos << endl;
		if(~valor) {
			ans.push_back(-pos + 1);
			
			update(-pos, valor-qt);
		}else ans.push_back(0);
	}
	for(auto el: ans) cout << el << ' ';
	cout << endl;
}
