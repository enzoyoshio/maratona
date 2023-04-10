#include <bits/stdc++.h>

using namespace std;

#define int long long

#define db(x) cerr << "[ " << #x << " = " << x << " ]\n"

const int oo = 1e15;
vector<int> cost;

int check(vector<int> v, int x, int k) {
	int n = v.size();

	for(int i = 0; k && i < n; i++) {
		int alvo = x/cost[i];

		if(alvo >= v[i]) continue;

		int dif = v[i] - alvo;

		if(k >= dif) {
			k -= dif;
			v[i] = alvo;
		}else {
			v[i] -= k;
			k = 0;
		}
	}

	for(int i = 0; i < n; i++)
		if(v[i]*cost[i] > x) return false;
	return true;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	cost.assign(n, 0);
	for(auto& it: v)
		cin >> it;
	for(auto& it: cost)
		cin >> it;

	sort(v.rbegin(), v.rend());
	sort(cost.begin(), cost.end());

	int sum = accumulate(v.begin(), v.end(), 0LL);

	if(sum <= k) return cout << 0 << endl, 0;

	int l = 0, r = 1e12, ans = oo;

	while(l <= r) {
		int mid = (l + r) >> 1;

		if(check(v, mid, k)) ans = mid, r = mid-1;
		else l = mid+1;
	}

	cout << ans << endl;
}
