#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	int x, y;
	cin >> x >> y;
	if(x > y) swap(x, y);

	vector<int> qt(y+1, 0);

	for(int i = 2; i < qt.size(); i++) {
		if(qt[i] == 0) {
			for(int j = i; j < qt.size(); j+=i) {
				int help = j;
				while(help%i == 0) qt[j]++, help/=i;
			}
		}
	}

	auto rg = [&](int tar) {
		return y/tar - (x-1)/tar;
	};

	int ans = 0;
	vector<int> res(y+1, 0);
	for(int i = 2LL; i <= y; i++) {

		cout << "i = " << i << " qt = " << qt[i] << endl;
		cout << "rg = " << rg(i) << endl;

		for(int j = i; j <= y; j+=i) {
			if(qt[i]%2) res[j] += rg(i);
			else res[j] -= rg(i);
		}

	}

	for(int i = 0; i < size(res); i++)
		cout << "i = " << i << " res[i] = " << res[i] << endl;
	for(int i = x; i <= y; i++)
		ans += res[i];
	cout << ans << endl;
}
