#include <bits/stdc++.h>

using namespace std;

#define int long long
using iii = array<int, 3>;
const int bucket = 500;

#define db(x) cerr << "[ " << #x << " = " << x << " ]\n"

long long choose3(int n) {
	return (long long)n*((long long)n-1)*((long long)n-2)/6LL;
}

long long choose(int n) { return choose3(n);}

void print(vector<int> v) {
	cout << "debugging qt\n";
	for(auto it: v) cerr << it << ' ';
	cerr << endl;
}

inline int64_t gilbertOrder(int x, int y, int pow, int rotate) {
	if (pow == 0) {
		return 0;
	}
	int hpow = 1 << (pow-1);
	int seg = (x < hpow) ? (
		(y < hpow) ? 0 : 3
			) : (
		(y < hpow) ? 1 : 2
			);
	seg = (seg + rotate) & 3;
	const int rotateDelta[4] = {3, 0, 0, 1};
	int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
	int nrot = (rotate + rotateDelta[seg]) & 3;
	int64_t subSquareSize = int64_t(1) << (2*pow - 2);
	int64_t ans = seg * subSquareSize;
	int64_t add = gilbertOrder(nx, ny, pow-1, nrot);
	ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
	return ans;
}

struct Query {
	int l, r, idx;
	int64_t ord;

	Query() {}

	Query(int ll, int rr, int i) {
		l = ll;
		r = rr;
		idx = i;
		calcOrder();
	}

	inline void calcOrder() {
		ord = gilbertOrder(l, r, 21, 0);
	}

};

inline bool operator<(const Query &a, const Query &b) {
	return a.ord < b.ord;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, q; cin >> n >> q;
	vector<int> v(n);
	for(auto& it: v) cin >> it;

	vector<Query> queries(q);
	for(int i = 0; i < q; i++) {
		int l, r; cin >> l >> r; l--, r--;
		queries[i] = Query(l, r, i);
	}

	sort(begin(queries), end(queries));
	/*
	sort(begin(queries), end(queries), [](iii a, iii b) {
			auto [al, ar, ai] = a;
			auto [bl, br, bi] = b;
			if(al/bucket != bl/bucket)
				return al/bucket < bl/bucket;
			return ((al / bucket) & 1 ) ? (ar > br) : (ar < br);
	});
	*/

	/*
	for(auto [a, b, id, ord]: queries) {
		cout << a << ' ' << b << ' ' << id << endl;
	}
	*/

	vector<long long> ans(q);
	vector<long long> qt((int)2e5+8);
	int curl = 0, curr = -1;
        long long res = 0;

	for(int i = 0; i < q; i++) {
		auto [queryl, queryr, id, ord] = queries[i];

		/*
		if(i == 0) {
			for(int j = queryl; j <= queryr; j++) {
				res -= choose3(qt[v[j]]);
				qt[v[j]]++;
				res += choose3(qt[v[j]]);
			}
			curl = queryl, curr = queryr;
			ans[id] = res;
			continue;
		}
		*/

		/*
		cerr << "---------------------------- db -----------------------\n";
		db(queryl);
		db(queryr);
		*/

		while(curl < queryl) {
			res -= choose3(qt[v[curl]]);
			qt[v[curl]]--;
			res += choose3(qt[v[curl]]);
			curl++;
			/*
			cerr << "----------------------------- update L -------------------------\n";
			db(res);
			db(curl);
			db(queryl);
			print(qt);
			*/
		}	

		while(curl > queryl) {
			--curl;
			res -= choose3(qt[v[curl]]);
			qt[v[curl]]++;
			res += choose3(qt[v[curl]]);
			/*
			cerr << "----------------------------- update L -------------------------\n";
			db(res);
			db(curl);
			db(queryl);
			print(qt);
			*/
		}

		while(curr < queryr) {
			++curr;
			res -= choose3(qt[v[curr]]);
			qt[v[curr]]++;
			res += choose3(qt[v[curr]]);
			/*
			cerr << "----------------------------- update R -------------------------\n";
			db(res);
			db(curr);
			db(queryr);
			print(qt);
			*/
		}

		while(curr > queryr) {
			res -= choose(qt[v[curr]]);
			qt[v[curr]]--;
			res += choose(qt[v[curr]]);
			curr--;
			/*
			cerr << "----------------------------- update R -------------------------\n";
			db(res);
			db(curr);
			db(queryr);
			print(qt);
			*/
		}

		/*
		cerr << "FINAL ANSWER -------------------> " << res << endl;
		print(qt);
		*/

		ans[id] = res;
	}

	for(auto el: ans) cout << el << '\n';
}
