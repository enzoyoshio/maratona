#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MAXN = 1e6+8;
#define next nt

vector<pair<char, int>> query(MAXN);
vector<int> ans(MAXN);
vector<int> print;
stack<int> last_active;
vector<vector<int>> next(MAXN);
int lastSeen = 0;
vector<int> vetor(MAXN);
set<int> difs;
multiset<int> rep;
int id = 0;

void dfs(int idx=0) {

	if(query[idx].first == '+') {
		difs.insert(query[idx].second);
		rep.insert(query[idx].second);
		vetor[id++] = query[idx].second;
		ans[idx] = difs.size();
	}else if(query[idx].first == '-') {
		auto [t, k] = query[idx];
		for(int i = 0; i < k; i++) {
			rep.erase(rep.find(vetor[id-1-i]));
			if(rep.find(vetor[id-1-1]) == rep.end())
				difs.erase(vetor[id-1-i]);
		}
		ans[idx] = difs.size();
		id -= k;
	}

	for(auto u: next[idx]) {
		if(query[u].first == '?') ans[u] = ans[idx];
		dfs(u);
	}
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int q;
	cin >> q;

	vector<pair<char,int>> active;
	for(int i = 0; i < q; i++) {
		char t; cin >> t;
		int x = 0;
		if(t == '+' || t == '-') cin >> x;
		query[q] = {t, x};
		if(t != '?') active.push_back(query[q]);
	}

	for(int i = 0; i < q; i++) {
		auto [t, x] = query[i];

		if(t == '?') {
			if(i == 0) ans[i] = 0;
			else ans[i] = ans[i-1];
			print.push_back(ans[i]);
			continue;
		}

		if(t == '+') {
			if(lastSeen)
				next[lastSeen].push_back(i);
			lastSeen = i;
			last_active.push(i);
		}else if(t == 'k') {
			if(lastSeen)
				next[lastSeen].push_back(i);
			lastSeen = i;
			last_active.push(i);
		}else {
			next[last_active.top()].push_back(i);
			last_active.pop();
		}
	}


	for(auto it: print) cout << it << '\n';
}
