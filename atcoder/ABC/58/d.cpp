#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MOD = 1e9 + 7;

int add(int a, int b) { 
	return ((a+b)%MOD + MOD)%MOD;
}
int sub(int a, int b) {
	return ((a-b)%MOD + MOD)%MOD;	
}
int mul(int a, int b) { return (a*b)%MOD;}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<int> xs(n), ys(m);
	for(auto& it: xs) cin >> it;
	for(auto& it: ys) cin >> it;

	sort(begin(xs), end(xs));
	sort(begin(ys), end(ys));

	int area = mul(sub(xs.back(), xs[0]), sub(ys.back(), ys[0]));
	int quad = mul(n-1, m-1);

	cout << mul(area, quad) << endl;
	
}
