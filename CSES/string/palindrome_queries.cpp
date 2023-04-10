#include <bits/stdc++.h>

#define int long long
#define pow pows

using namespace std;

const int MOD = 1e9+9;
const int p = 51;
const int MAXN = 2e5+8;
int n, m;
string s;
vector<int> inv(MAXN), pow(MAXN);

int fexp(int b, int e) {
	if(e == 0) return 1LL;

	int x = fexp(b, e/2);
	x = (x*x)%MOD;

	if(e%2) x = (x*b)%MOD;

	return x;
}

struct ST {
	vector<int> st;
	
	ST(string t) {
		st.assign(4*MAXN, 0);
		build(t);
	}

	void build(string t, int sti=1, int stl=1, int str=n) {
		if(stl == str) {
			st[sti] = ((t[stl-1]-'a'+1)*pow[stl])%MOD;
			return;	
		}

		int mid = (stl+str) >> 1, e = (sti << 1), d = (sti << 1) +1;

		build(t, e, stl, mid);
		build(t, d, mid+1, str);

		st[sti] = (st[e] + st[d])%MOD;
	}

	void update(int idx, int val, int sti=1, int stl=1, int str=n) {
//		cout << "--------------------- dentro do update ------------------------ \n";
//		cout << "idx = " << idx << " val = " << val << " sti = " << sti << " stl = " << stl << " str = " << str << endl;
		if(idx > str || idx < stl) {
			//cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> deu ruim\n";
			return;
		}
		if(stl == str) {
			//cout << "debug dentro da segtree\n";
			//cout << st[sti] << endl;
			st[sti] = ((val)*pow[stl])%MOD;
			//cout << st[sti] << endl;
			//cout << "fim debug\n";
			return;	
		}
		int mid = (stl+str) >> 1, e = (sti << 1), d = (sti << 1) +1;
		update(idx, val, e, stl, mid);
		update(idx, val, d, mid+1, str);
		st[sti] = (st[e] + st[d])%MOD;
	}	

	int query(int A, int B, int sti=1, int stl=1, int str=n) {
		if(A > str || B < stl) return 0;
		if(A <= stl && str <= B) return st[sti];
		int mid = (stl+str) >> 1, e = (sti << 1), d = (sti << 1) +1;
		return (query(A, B, e, stl, mid) + query(A, B, d, mid+1, str))%MOD;
	}
};

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	cin >> n >> m >> s;

	pow[0] = 1;
	for(int i = 1; i < MAXN; i++)
		pow[i] = (pow[i-1]*p)%MOD;

	inv[MAXN-1] = fexp(pow[MAXN-1], MOD-2);
	for(int i = MAXN-2; i >= 0; i--)
		inv[i] = (inv[i+1]*p)%MOD;

//	for(int i = 0; i < n; i++)
		//cout << pow[i] << ' ';
//	//cout << endl;
//	for(int i = 0; i < n; i++)
		////cout << inv[i] << ' ';
	//cout << endl;

	ST st(s);
	reverse(s.begin(), s.end());
	ST strev(s);

	while(m--) {
		int t;
		cin >> t;

		if(t == 1) {
			
			int k; char x;
			cin >> k >> x;
			
//			cout << "entrei aqui\n";
			st.update(k, x-'a'+1);
			strev.update(n-k+1, x-'a'+1);
		}else {
			int a, b; cin >> a >> b;	

//			//cout << "-------------------------------------------------------\n";
			//cout << st.query(a, b) << ' '<< strev.query(n-b+1, n-a+1) << endl;
			//cout << a << ' ' << b << ' ' << n-b+1 << ' ' << n-a+1 << endl;
			//cout << inv[a-1] << ' ' << inv[n-b] << endl;
			//cout << st.query(a, b) * inv[a-1] << ' ' << strev.query(n-b+1, n-a+1) * inv[n-b] << endl;
			if(st.query(a, b)*inv[a-1] == strev.query(n-b+1, n-a+1)*inv[n-b]) cout << "YES\n";
			else cout << "NO\n";
		}
	}
}
