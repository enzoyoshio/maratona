#include <bits/stdc++.h>

using namespace std;

#define YES cout << "Yes\n"
#define NO cout << "No\n"
using ii = pair<int,int>;
const int oo = 1e8;

struct ST {
	vector<ii> st;
	int n;
	ii zero{0, 1};

	ST() {}

	ST(int n) : n(n), st(4*n, {0, 0}) {}

	ii f(ii a, ii b) { return {max(a.first, b.first), min(a.second, b.second)};}
	
	ii update(int x, int v, int sti, int stl, int str) {
		if(x > str || x < stl) return st[sti];
		
		if(stl == str) { return st[sti] = {v, v};}

		int stm = (stl+str)/2, ste = sti*2, std = sti*2+1;

		return st[sti] = f(update(x, v, ste, stl, stm),
				   update(x, v, std, stm+1, str));
	}
	ii update(int x, int v) { return update(x, v, 1, 0, n-1);}

	ii query(int L, int R, int sti, int stl, int str) {
		if(L > str || R < stl) return zero;
		
		if(L <= stl && str <= R) return st[sti];

		int stm = (stl+str)/2, ste = sti*2, std = sti*2+1;

		return f(query(L, R, ste, stl, stm),
		       query(L, R, std, stm+1, str));
	}
	ii query(int L, int R) { return query(L, R, 1, 0, n-1);}
	
};

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	string s;
	cin >> n >> s;

	// make segtree
	ST inc(n);
	for(int i = 1; i < n; i++) {
		inc.update(i, s[i-1] <= s[i]);
	}

	vector<ST> freq(26);
	for(int i = 0; i < 26; i++)
		freq[i] = ST(n);

	for(int i = 0; i < n; i++) {
		freq[s[i]-'a'].update(i, 1);
	}

	int q;
	cin >> q;
	while(q--) {
		int t;
		cin >> t;

		if(t == 1) {
			int x; char c;
			cin >> x >> c; x--;

			freq[s[x]-'a'].update(x, 0);
			freq[c-'a'].update(x, 1);
			s[x] = c;
			if(x)
				inc.update(x, s[x-1] <= s[x]);
			if(x+1 < n)
				inc.update(x+1, s[x] <= s[x+1]);
		}else if(t == 2) {
			int l, r;
			cin >> l >> r; l--, r--;

			if(l == r) {
				YES;
				continue;
			}
			
			bool can = true;
			for(int i = s[l]+1; i < s[r]; i++) {
				if(l)
					can &= freq[i-'a'].query(0, l-1).first == 0;
				if(r+1 < n)
					can &= freq[i-'a'].query(r+1, n-1).first == 0;
			}

			/*
			cout << "\n\n\noioioi\n";
			cout << inc.query(l+1, r).second << endl;
			for(int i = l+1; i <= r; i++)
				cout << inc.query(i, i).second << endl;
			*/

			if(inc.query(l+1, r).second == 1 && can) 
				YES;
			else NO;
		}
	}
}
