#include <bits/stdc++.h>

using namespace std;

#define db(x) cout << "[ " << #x << " = " << x << " ]\n"

void printans(pair<int,int> a) {
	cout << "taking from " << a.first << " to " << a.second << endl;
}

void print(vector<vector<int>> m) {

	cout << "estado atual\n";
	for(auto l: m) {
		for(auto el: l) cout << el << ' ';
		cout << endl;
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> fim(n);

	for(int i = 0; i < n; i++) {
		int t; cin >> t;
		for(int j = 0; j < t; j++) {
			int a; cin >> a;
			a--;
			fim[i].push_back(a);
		}
	}

	vector<pair<int,int>> ans;

	vector<vector<int>> cur(n);
	for(int i = 0; i < n-1; i++) {
		for(int j = 0; j < m; j++)
			cur[i].push_back(i);
	}

	auto give = [&](int idx, int protect) -> pair<int,int> {
		int last = -1;
		for(int i = n-1; i >= 0; i--) {
			if(idx == i) continue;
			if(cur[i].size() == m) continue;

			if(cur[i].size() && cur[i].back() == protect) {
				last = i;
				continue;	
			}

			cur[i].push_back(cur[idx].back());
			cur[idx].pop_back();
			return {idx, i};
		}

		cur[last].push_back(cur[idx].back());
		cur[idx].pop_back();
		return {idx, last};
	};

	auto take = [&](int idx, int want) -> pair<int,int> {
		int last = -1;
		for(int i = n-1; i >= 0; i--) {
			if(idx == i) continue;
			if(cur[i].empty()) continue;

			if(i > idx && cur[i].size() == fim[i].size())
				continue;

			if(cur[i].back() == want) {
				cur[idx].push_back(want);
				cur[i].pop_back();
				return {i, idx};
			}
		}
		return {-1, -1};
	};


	for(int i = n-1; i >= 0; i--) {
		int idx = 0;
		while(idx < fim[i].size()) {

			// enquanto a pilha atual tiver
			// mais elementos do q idx elementos
			// eu tiro esses elementos
			while((int)cur[i].size() > idx+1) {
				/*
				cerr << "--------------- db -=----\n";
				db(i);
				db(cur[i].size());
				db(idx);
				*/
				ans.push_back(give(i, fim[i][idx]));
				/*
				db(ans.back().first);
				db(ans.back().second);
				*/

	//			printans(ans.back());
	//			print(cur);
			}
			
			// se o elemento do topo
			// for igual o que eu quero, next
			if(cur[i].size() == idx+1 && cur[i].back() == fim[i][idx]) {
				idx++;
				continue;
			}else if(cur[i].size() == idx+1) {
				ans.push_back(give(i, fim[i][idx]));
	//			printans(ans.back());
	//			print(cur);
			}

			pair<int,int> p;
			while(p = take(i, fim[i][idx]),
					p.first == -1) {
				ans.push_back(give(fim[i][idx], i));
			}
			ans.push_back(p);
			/*
			printans(ans.back());
			print(cur);
			*/
			/*
			cout << "taking " << ans.back().first+1 << ' ' << ans.back().second+1 << endl;
			db(i);
			db(fim[i][idx]);
			*/

			idx++;
		}

	}

	/*
	cout << "final state\n";
	for(auto it: cur) {
		for(auto el: it) cout << el+1 << ' ';
		cout << endl;
	}
	*/

//	assert(ans.size() < 2000000);
	cout << ans.size() << '\n';
	for(auto [a, b]: ans) cout << a+1 << ' ' << b+1 << '\n';

}
