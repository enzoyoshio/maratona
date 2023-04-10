#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for(auto& el: v)
		cin >> el;

	int ma = *max_element(v.begin(), v.end()), mi = *min_element(v.begin(), v.end());

	int upper = ma - mi;

	if(!upper) {
		cout << "No\n";
		return;
	}

	vector<int> pos, neg, ans;
	for(int i = 0; i < n; i++) {
		if(!v[i]) ans.push_back(0);
		else if(v[i] > 0) pos.push_back(v[i]);
		else neg.push_back(v[i]);
	}

	if(neg.size() > pos.size()) swap(pos, neg);

	sort(pos.rbegin(), pos.rend());
	sort(neg.rbegin(), neg.rend());

	int acum = 0, idx = 0;
	for(int i = 0; i < pos.size(); i++) {
		if(idx < (int)neg.size() && abs(acum + pos[i]) >= upper)
			ans.push_back(neg[idx]), acum += neg[idx++];
		acum += pos[i];	
		ans.push_back(pos[i]);
	}

	while(idx < (int)neg.size()) {
		ans.push_back(neg[idx]);
		acum += neg[idx++];
		if(acum > upper) {
			cout << "No\n";
			return;
		}
	}

	/*
	for(int i = 0; i < n; i++) {
		for(int j = i; j < n; j++) {
			int s = 0;
			for(int k = i; k <= j; k++)
				s += ans[k];
			if(s > upper) 
				assert(false);
		}
	}
	*/

	cout << "Yes\n";
	for(auto el: ans) 
		cout << el << ' ';
	cout << endl;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t = 1;
	cin >> t;
	while(t--) solve();
}
