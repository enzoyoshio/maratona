#include <bits/stdc++.h>
using namespace std;

// Template (v1.4.0 - 2023-04-19) (codeforces:cebolinha, atcoder:edu) {{{

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#define int long long
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)

template<class T> using V = vector<T>;
template<class T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
using ii = pair<int, int>;
using iii = array<int, 3>;

#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define sz(x) (int) (x).size()
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define nemo ><>
#define loop(ii, n) for (int ii = 0; ii < (n); ii++)
#define cond(c, t, f) ((c) ? (t) : (f))
#define mem(a, b) memset((a), (b), sizeof(a))
#define inbounds(x, l, r) ((l) <= (x) && (x) <= (r))
#define L1(res...) [&](auto x){ return res; }
#define L2(res...) [&](auto x, auto y){ return res; }

template<class T, class U> inline void miq(T& a, U b){ if (a > b) a = b; }
template<class T, class U> inline void maq(T& a, U b){ if (a < b) a = b; }

#define db(x) cerr << "[ " << #x << " = " << (x) << " ]\n"
//}}}

const int oo = -1e10;
const int MAXN = 2e5+8;
int N;
vector<int> st(4*MAXN, oo);

int merge(int a, int b) {
	return max(a, b);
}

int update(int id, int x, int sti=1, int stl=0, int str=N-1) {

	if(stl > id || str < id) return st[sti];

	if(stl == str)
		return st[sti] = x;

	int stm = (stl+str)/2, ste = 2*sti, std = 2*sti+1;

	int up1 = update(id, x, ste, stl, stm);
	int up2 = update(id, x, std, stm+1, str);
	return st[sti] = merge(up1, up2);
}

int query(int l, int r, int sti=1, int stl=0, int str=N-1) {

	if(l > str || r < stl) {
		return oo;
	}

	if(l <= stl && str <= r) {
		return st[sti];
	}

	int stm = (stl+str)/2, ste = 2*sti, std = 2*sti+1;

	return merge(query(l, r, ste, stl, stm), query(l, r, std, stm+1, str));
}

auto main() -> signed {
	fastio;

	int n, m;
	cin >> n >> m;
	N = m;
	vector<int> v(m);
	for(auto& it: v)
		cin >> it;

	for(int i = 0; i < N; i++)
		update(i, v[i]);

	int q;
	cin >> q;

	while(q--) {
		int x1, y1, x2, y2, k;
		cin >> x1 >> y1 >> x2 >> y2 >> k;
		y1--, y2--;
		if(y1 > y2) swap(y1, y2), swap(x1, x2);

		// se eu nao consigo dar um pulo de tamanho k
		// em uma das coordenadas, entao ja eh impossivel
		if(abs(x1-x2)%k || abs(y1-y2)%k) {
		//	cerr << "no pq nao da pra fazer pulo de tamanho k\n";
			cout << "NO\n";
			continue;
		}

		int pos = x1%k;
		// como otimizar essa parte?
		// qual estrutura consegue saber o max de um range mod k, para algum k
		// acho que so uma seg de minimo funciona

		int maxi = query(y1, y2);
		
		// tenho a maior pilha, como eu descubro se o cara pode passar por la? 
		// se eu tenho x%k, vou pulando de k em k
		// entao eu tenho q saber se o x%k ta entre maxi%k e n%k?

		// pelo principio da casa dos pombos eu acho
		// isso aqui garante que ele passa
		/*
		db(n);
		db(maxi);
		db(k);
		db(y1);
		db(y2);
		db(query(y1, y2));
		db(query(3, 3));
		db(query(2, 2));
		db(query(4, 4));
		db(query(2, 4));
		*/
		if(n-maxi-1 >= k) {
		//	cerr << "yes pq tem espaco\n";
			cout << "YES\n";
			continue;
		}

		// se o caminho todo estiver bloqueado
		if(n == maxi) {
		//	cerr << "no pq algum dos blocos ta bloqueado\n";
			cout << "NO\n";
			continue;
		}

		// se o caminho nao tiver bloqueado
		// entao passo de tamanho 1 sempre chega no lugar
		if(k == 1) {
		//	cerr << "yes pq o k = 1\n";
			cout << "YES\n";
			continue;
		}

		int mk = maxi%k, nk = n%k;
		// se tiver um intervalo normal
		/*
		db(mk);
		db(nk);
		db(pos);
		*/
		if(mk < nk) {
			if(mk < pos && pos <= nk) cout << "YES\n";
			else cout << "NO\n";
		}else {
			if(pos <= maxi%k && pos > n%k) cout << "NO\n";
			else cout << "YES\n";
		}
	}
}

// how do I know that the robot can pass through a column to another?  
// se eu tenho tipo a%p1 = x, a%p2=y, a%p3=z, com p1, p2, p3 primos, 
// eu consigo descobrir a%(p1*p2*p3)?
// a%(num);
// num = p1*p2*p
