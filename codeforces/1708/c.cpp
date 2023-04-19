#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t; while(t--) {
		int n, q;
		cin >> n >> q;
		vector<int> v(n);
		for(auto& it: v)
			cin >> it;

		// se tiver mto q, entao eu posso so testar
		// todos os dias
		if(q >= n) {
			for(auto it: v)
				cout << 1;
			cout << endl;
			continue;
		}

		// se nenhum dia q ela testar nao va manter os dias
		// entao eh so imprimir q dias
		if(*min_element(begin(v), end(v)) > q) {
			for(int i = 0; i < n; i++)
				cout << (i < q ? 1 : 0);
			cout << endl;
			continue;
		}

		string ans = "";
		int cur = 0;
		for(int i = n-1; i >= 0; i--) {
			if(cur >= v[i]) ans+='1';
			else if(cur + 1 <= q) 
				cur++, ans += '1';
			else ans += '0';
		}

		reverse(begin(ans), end(ans));
		cout << ans << endl;
	}
}
