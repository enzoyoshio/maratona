#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MOD = 998244353;

int add(int a, int b) { return (a+b)%MOD;}
int mul(int a, int b) { return (a*b)%MOD;}
int mod(int a) { return a%MOD;}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int q, n, m;
	cin >> n >> m;
	cin >> q;

	auto calc = [&](int r1, int r2, int c1, int c2) -> int {
		if(r1 > r2 || c1 > c2) return 0LL;
		int v = (r1-1)*m + c1;
		int cols = (c2-c1)/2 + 1;
		int rows = (r2-r1)/2 + 1;

		//int s = add(mul(v,cols), add(cols-1, mod((cols-1)*(cols-1))));

		// cols -> quantidade de caras em uma linha
		// para calcular a soma de uma linha
		// (cols-1)^2 + cols-1 + cols*((r1-1)*M + c1)
		//
		int other = mul(rows, add((cols-1)*(cols-1), cols-1));
		int o = mul(rows, c1);
		o = add(o, mul(m, add(mul(r1, rows), mod((rows-1)*(rows-1)-1))));
		o = mul(o, cols);
		other = add(other, o);
		/*
		cout << "lines\n";
		cout << other << endl;
		*/
		return other;
	};

	while(q--) {
		int a, b, c, d;

		cin >> a >> b >> c >> d;

		int ans = 0;
		// o primeiro quadrado eh impar -> 0
		if( (a+c)%2) {
			ans = add(calc(a, b, c+1, d), calc(a+1, b, c, d));
		}else { // o primeiro quadrado eh par -> par
			ans = add(calc(a+1, b, c+1, d), calc(a, b, c, d));	
		}
		cout << ans << '\n';
	}
}
