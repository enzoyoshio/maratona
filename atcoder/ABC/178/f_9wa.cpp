#include <bits/stdc++.h>

using namespace std;
using iii = array<int, 3>;

#define db(x) cerr << "[ " << #x << " = " << x << " ]\n"

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> a(n), b(n), fa(n), fb(n);

	for(auto& it: a) cin >> it, it--, fa[it]++;
	for(auto& it: b) cin >> it, it--, fb[it]++;

	for(int i = 0; i < n; i++)
		if(fa[i] + fb[i] > n)
			return cout << "No\n", 0;	

	if(n == 1) {
		if(a[0] == b[0]) return cout << "No\n", 0;
		return cout << "Yes\n" << b[0]+1 << endl, 0;
	}

	vector<int> ans(n);
	set<iii> sb;
	vector<pair<int,int>> vb(n);
	for(int i = 0; i < n; i++) {
		vb[i] = {fb[i], i};
	}
	sort(rbegin(vb), rend(vb));

	for(int i = 0; i < n; i++) {
		if(vb[i].first)
			sb.insert(iii{i, vb[i].first, vb[i].second});
	}

	for(auto [pos, qt, id]: sb) {
		cout << pos << ' ' << qt << ' ' << id << endl;
	}

	for(int i = 0; i < n; i++) {
		auto [pos, qt, id] = *begin(sb);
		sb.erase(begin(sb));

		db(id);
		db(a[i]);
		db(i);

		if(id == a[i]) {
			auto [pos1, qt1, id1] = *begin(sb);
			sb.erase(begin(sb));

			cout << id1 << endl;
			ans[i] = id1+1;
			if(qt1-1)
				sb.insert(iii{pos1, qt1-1, id1});
			sb.insert(iii{pos, qt, id});
		}else {
			cout << id << endl;
			ans[i] = id+1;
			if(qt-1)
				sb.insert(iii{pos, qt-1, id});
		}
	}

	cout << "Yes\n";
	for(auto el: ans) cout << el << ' ';
	cout << endl;
}
