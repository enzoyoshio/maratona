#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;
const int MAXN = 1e6+8;
vector<int> fact(MAXN), inv(MAXN);

int add(int a, int b) {
	return (a+b)%MOD;
}

int sub(int a, int b) {
	return ((a-b)%MOD + MOD)%MOD;
}

int mul(int a, int b) {
	return ((long long)a * (long long)b)%MOD;
}

int fexp(int b, int e=MOD-2) {
	if(e == 0) return 1;

	int x = fexp(b, e/2);
	x = mul(x, x);

	if(e%2) x = mul(b, x);

	return x;
}

int C(int n, int k) {
	return mul(mul(fact[n], inv[k]), inv[n-k]);
}

int main() {
	int h, w, k;
	cin >> h >> w >> k;

	fact[0] = 1;
	for(int i = 1; i < (int)fact.size(); i++)
		fact[i] = mul(fact[i-1], i);

	inv.back() = fexp(fact.back());
	for(int i = MAXN-2; i >= 0; i--) {
		inv[i] = mul(inv[i+1], i+1);
	}

	// se so tiver que colocar 1 quadrado
	// o valor esperado do retangulo sera 1
	// pq so vai ter quadrado de tamanho 1
	if(k == 1)
		return cout << 1 << endl, 0;


}
