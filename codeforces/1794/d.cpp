#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;
const int MAXN = 2e6;
vector<int> fact(MAXN), inv(MAXN);

int add(int a, int b) {
	return (a+b)%MOD;
}

int mul(int a, int b) {
	return ((long long)a * (long long)b)%MOD;
}

int fexp(int b, int e=MOD-2) {
	if(e == 0) return 1;

	int x = fexp(b, e/2);
	x = mul(x, x);

	if(e%2) x = mul(x, b);

	return x;
}

int C(int n, int x) {
	int ans = fact[n];
       	ans = mul(ans, inv[x]);
	ans = mul(ans, inv[n-x]);
	return ans;	
}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	vector<int> crivo(MAXN, 1);
	crivo[0] = crivo[1] = 0;
	for(int i = 2; i < MAXN; i++) {
		if(crivo[i]) {
			for(int j = i+i; j < MAXN; j+=i) crivo[j] = 0;
		}
	}

	fact[0] = 1;
	for(int i = 1; i < MAXN; i++)
		fact[i] = mul(fact[i-1], i);

	inv[MAXN-1] = fexp(fact[MAXN-1]);
	for(int i = MAXN-2; i >= 0; i--)
		inv[i] = mul(inv[i+1], i+1);

	int n;
	cin >> n;
	vector<int> v(2*n);
	vector<int> primes, onlyOne;
	map<int,int> freq;
	for(auto& el: v)
		cin >> el;
	for(auto el: v) {
		if(crivo[el])
			primes.push_back(el);
		freq[el]++;
	}

	int ans = 0;
	sort(primes.begin(), primes.end());
	for(auto p: primes) {
		if(onlyOne.empty() || onlyOne.back() != p)
			onlyOne.push_back(p);
	}


	if(onlyOne.size() < n) 
		return cout << 0 << endl, 0;

	// enquanto eu puder pegar N caras;
	for(int i = 0; i+n-1 < (int)onlyOne.size(); i++) {
		int aux = C((int)onlyOne.size() - (i+1), n-1);

		int aux2 = fact[n];
		for(auto [a, b]: freq) {
			if(b == 1) continue;
			if(a >= onlyOne[i] && crivo[a]) {
				if(b > 1)
					aux2 = mul(aux2, inv[b-1]);
			}else 
				aux2 = mul(aux2, inv[b]);
		}

		aux = mul(aux, aux2);

		ans = add(ans, aux);
	}
	
	cout << ans << endl;
}
