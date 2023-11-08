#include <bits/stdc++.h>

using namespace std;
#define int long long

#define db(x) cerr << "[ " << #x << " = " << x << " ]\n"

int n, m, q;
vector<int> st;

int update(int x, int val, int sti=1, int stl=0, int str=n-1) {
	if(x > str || x < stl) return st[sti];
	if(stl == str) return st[sti] = val;
	int stm = (stl+str)/2, ste = 2*(sti), std = 2*sti+1;
        return st[sti] = update(x, val, ste, stl, stm) + update(x, val, std, stm+1, str);	
}

int query(int L, int R, int sti=1, int stl=0, int str=n-1) {
	if(L > R) return 0;
	if(L < 0 || R < 0) return 0;

	if(L > str || R < stl) return 0;
	
	if(L <= stl && str <= R) {
		return st[sti];
	}

	int stm = (stl+str)/2, ste = 2*(sti), std = 2*sti+1;
	return query(L, R, ste, stl, stm) + query(L, R, std, stm+1, str);	
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	cin >> n >> m >> q;
	st.resize(4*n);
	string s;
	cin >> s;
	vector<pair<int,int>> p(m);
	for(auto& [a, b]: p) cin >> a >> b, a--, b--;

	set<int> conj;
	for(int i = 0; i < n; i++)
		conj.insert(i);
	vector<int> ord;
	vector<int> to(n);

	for(auto [a, b]: p) {
		auto proc = conj.lower_bound(a);

		while(proc != end(conj) && *proc <= b) {
			ord.push_back(*proc);
			proc = conj.erase(proc);
			to[ord.back()] = (int)ord.size()-1;
		}
	}

	for(int i = 0; i < ord.size(); i++) {
		update(i, s[ord[i]] == '1');
	}

	// se nao tao no range
	set<int> ativo;
	for(int i = 0; i < n; i++) {
		if(conj.find(i) != conj.end()) {
			if(s[i] == '1') ativo.insert(i);
		}	
	}

	while(q--) {
		int x; cin >> x;
		x--;

		// so mudou o numero de fora
		if(conj.find(x) != conj.end()) {
			// o bit ta ligado -> tem q desligar
			if(ativo.find(x) != ativo.end()) {
				ativo.erase(x);
			}else {
				// bit ta desativado
				// tem q ligar
				ativo.insert(x);
			}
		}else {
			if(s[x] == '1') {
				update(to[x], 0);
				s[x] = '0';
			}else {
				update(to[x], 1);
				s[x] = '1';
			}
		}

		int coloca = query(0, ord.size()-1);
		int full = min((int)ord.size(), (int)(size(ativo)) + coloca);
		cout << full - query(0, full-1) << '\n';
	}
}
