#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MAXM = 1e6+8;
const int MAXN = 2e5+8;
const int MAXL = 22;

using no = array<int,3>; 
no zero{0, -2*MAXN, 2*MAXN};
bitset<MAXM> a;
vector<int> phi(MAXM);

void crivo() {
	a.set();
	a[0] = a[1] = 0;

	phi[1] = 1;
	for(int i = 2; i < MAXM; i++) {
		phi[i] = i;
		if(i%2 == 0)
			phi[i] /= 2;
	}

	for(int i = 3; i < MAXM; i+=2) {
		if(a[i]) {
			for(int j = i; j < MAXM; j+=i) {
				a[j] = false;
				phi[j] /= i;
				phi[j] *= (i-1);
			}
		}
	}
}

void maq(int& a, int b) {
	if(b > a) a = b;
}

void miq(int& a, int b) {
	if(b < a) a = b;
}

// segtree stores sum, max, min
struct ST {
	vector<int> lazy;
	vector<no> st;
	int n;

	ST(int _n) : n(_n), st(4*_n, zero), lazy(4*_n, 0) {}

	no merge(no a, no b) {
		a[0] += b[0];
		maq(a[1], b[1]);
		miq(a[2], b[2]);
		return a;
	}

	void prop(int sti, int stl, int str) {

		if(lazy[sti]) {
			
			st[sti] = {lazy[sti]*(str-stl+1), lazy[sti], lazy[sti]};

			if(stl != str)
				lazy[2*sti] = lazy[2*sti+1] = lazy[sti];

			lazy[sti] = 0;
		}
	}

	void apply_phi(int sti, int stl, int str) {
		
		int phix = phi[st[sti][1]];
		st[sti][0] = (str-stl+1)*phix;
		st[sti][2] = st[sti][1] = phix;
		if(stl != str)
			lazy[2*sti] = lazy[2*sti+1] = phix;
	}

	// update1 -> apply phi(ai) in range [L, R]
	no update1(int L, int R, int sti, int stl, int str) {
		prop(sti, stl, str);
		if(L > str || stl > R) return st[sti];

		// muda o negocio de parada
		// se o max == min -> esse range eh todo igual
		if(L <= stl && str <= R && st[sti][1] == st[sti][2]) {
			apply_phi(sti, stl, str);
			return st[sti];
		}

		int stm = (stl+str)/2, ste=2*sti, std=2*sti+1;
		return st[sti] = merge(update1(L, R, ste, stl, stm),
				       update1(L, R, std, stm+1, str));


	}
	no update1(int L, int R) { return update1(L, R, 1, 0, n-1);}

	// update2 -> apply ai = x to range [L, R]
	no update2(int L, int R, int x, int sti, int stl, int str) {
		prop(sti, stl, str);
		if(L > str || stl > R) return st[sti];

		if(L <= stl && str <= R) {
			lazy[sti] = x;
			prop(sti, stl, str);
			return st[sti];
		}

		int stm = (stl+str)/2, ste=2*sti, std=2*sti+1;
		return st[sti] = merge(update2(L, R, x, ste, stl, stm),
				       update2(L, R, x, std, stm+1, str));

	}
	no update2(int L, int R, int x) { return update2(L, R, x, 1, 0, n-1);}

	// query -> sum of range
	no query(int L, int R, int sti, int stl, int str) {
		prop(sti, stl, str);
		if(L > str || stl > R) return zero;
		if(L <= stl && str <= R) return st[sti];
		int stm = (stl+str)/2, ste=2*sti, std=2*sti+1;
		return merge(query(L, R, ste, stl, stm),
			     query(L, R, std, stm+1, str));
	}
	no query(int L, int R) { return query(L, R, 1, 0, n-1);}
};

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	crivo();

	int n, q;
	cin >> n >> q;
	ST st(n);
	for(int i = 0; i < n; i++) {
		int a; cin >> a;
		st.update2(i, i, a);
	}

	for(int i = 0; i < q; i++) {
		int t, l, r;
		cin >> t >> l >> r;
		l--, r--;

		if(t == 1) {
			st.update1(l, r);	
		}else if(t == 2) {
			int x; cin >> x;
			st.update2(l, r, x);
		}else {
			cout << st.query(l, r)[0] << '\n';
		}
	}
}
