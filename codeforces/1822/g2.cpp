#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXV = 4e4;
const int MAXN = 1e9;
vector<int> primes;

void build() {

	bitset<MAXV> a;
	a.set();
	a[0] = a[1] = 0;

	for(int i = 0; i < MAXV; i++) {
		if(a[i]) {
			primes.push_back(i);
			for(int j = i+i; j < MAXV; j+=i)
				a[j] = 0;
		}
	}
}

vector<pair<int,int>> fact(int n) {
	vector<pair<int,int>> v;
	v.reserve((int)primes.size());
	for(auto el: primes) {
		if(el*el > n) break;
		int qt = 0;
		while(n%el == 0) {
			qt++;
			n /= el;
		}
		v.emplace_back(el, qt);
	}

	if(n > 1) v.emplace_back(n, 1);

	return v;
}
 
void get_divisors(vector<pair<int,int>> const& f, int idx, int x, int num, int& el, vector<pair<int,int>> const& counti) {
  if (idx == (int)f.size()){
    if(x > 1 && num%(x*x) == 0) {
	//cout << num << ' ' << x << endl;
	auto p1 = lower_bound(begin(counti), end(counti), pair<int,int>(num, -1));
	auto p2 = lower_bound(begin(counti), end(counti), pair<int,int>(num/x, -1));
	auto p3 = lower_bound(begin(counti), end(counti), pair<int,int>(num/(x*x), -1));

	if(p1 == end(counti) || p2 == end(counti) || p3 == end(counti) 
	|| p1->first != num || p2->first != num/x || p3->first != num/(x*x))
		return;

	el += p1->second * p2->second * p3->second;
    }
    return;
  }

  for(int i = 0; i <= f[idx].second; i++) {
    get_divisors(f, idx+1, x, num, el, counti);
    x *= f[idx].first;
  }
}

void solve() {
	int n;
	cin >> n;
	unordered_map<int,int> f;
	f.reserve(n);
	for(int i = 0; i < n; i++) {
		int a; cin >> a;
		f[a]++;
	}

	vector<pair<int,int>> vv;
	for(auto [a, b]: f)
		vv.emplace_back(a, b);
	sort(begin(vv), end(vv));

	int ans = 0;
	for(auto [a, b]: f) {
		ans += b*(b-1)*(b-2);
		auto factors = fact(a);
		get_divisors(factors, 0, 1, a, ans, vv);
	}
	cout << ans << endl;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	build();
	int t=1;
	cin >> t;
	while(t--) solve();
}
