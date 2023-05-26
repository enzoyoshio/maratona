#include <bits/stdc++.h>

using namespace std;

#define int long long

const int oo = 1e15;

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for(auto& it: v)
		cin >> it;

	int tot = accumulate(v.begin(), v.end(), 0LL);

	if(k == 1)
		return cout << tot << endl, 0;

	if(k == 2) {
		for(int i = 1; i < n; i++)
			v[i] += v[i-1];

		int ans = oo;
		for(int i = 0; i+1 < n; i++)
			ans = min(ans, max(v[i], v.back()-v[i]));	
    cout << ans << endl;
		return 0;
	}

	int mx = *max_element(v.begin(), v.end());

	// se o maior elemento ja for maior que 
	// tudo ai ja nao da
	if(mx > tot/k)
		return cout << "oi " << mx << endl, 0;

	// isso eh so um guloso?
	int want = tot/k;

	int soma = 0, ans = 0;
	for(int i = 0; i < n && k; i++) {
		if(soma + v[i] > want) {
			if(k == 1) {
				int j = i;
				while(j < n) soma += v[j++];
				ans = max(ans, soma);
				soma = 0;
				break;	
			}
			//cout << soma << endl;
			ans = max(ans, soma);
			soma = v[i];
			k--;
		}else
			soma += v[i];
	}
	ans = max(ans, soma);

	cout << ans << endl;
}
