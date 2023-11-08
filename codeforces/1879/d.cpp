#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MOD = 998244353;

int add(int a, int b) { return (a+b)%MOD;}
int sub(int a, int b) { return ((a-b)%MOD+MOD)%MOD;}
int mul(int a, int b) { return (a*b)%MOD;}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> v(n);
	for(auto& it: v) cin >> it;

	int ans = 0;
	vector qt(2, vector<int>(35, 0));
	vector sum(2, vector<int>(35, 0));
	for(int i = 0; i < 35; i++)
		qt[0][i] = 1;

	vector cur(35, 0);
	// para cada elemento
	for(int i = 0; i < n; i++) {
		// para cada bit
		for(int bit = 0; bit < 35; bit++) {
			cur[bit] ^= (bool)((v[i] >> bit) & 1);
			
			int curA = 0;
			// se tiver ativo
			curA = mul(i+1, qt[!cur[bit]][bit]);
			curA = sub(curA, sum[!cur[bit]][bit]);
			ans = add(ans, mul(curA, 1LL << bit));
			qt[cur[bit]][bit]++;
			sum[cur[bit]][bit] = add(sum[cur[bit]][bit], i+1);
		}
	}
	cout << ans << endl;
}
