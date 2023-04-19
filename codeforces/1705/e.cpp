#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;
vector<int> freq(MAXN);
vector<int> reach(MAXN);

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, q;
	cin >> n >> q;
	vector<int> v(n);
	for(auto& it: v)
		cin >> it, freq[it]++;

	auto get_lead = [](int a) {
		int leading = 0;
		for(int j = 0; j < 21; j++) {
			if(((1 << j) & a) != 0) leading = j;
		}
		return leading;
	};

	int ans = 0;
	for(int i = 0; i < MAXN; i++) {
		int leading = get_lead(freq[i]);

		// leading eh o pulo
		if(leading)
			freq[i+leading]++;

		if(freq[i]) ans = i;
	}

	for(int i = 0; i < q; i++) {
		int pos, a; cin >> pos >> a; pos--;

		int leading;
		while(leading = get_lead(freq[pos]), leading) {
			freq[pos]--;
			pos = freq[pos+leading];
		}

		while(leading = get_lead(freq[a]), leading) {
			freq[a]--;
			a = freq[a+leading];
		}

		if(a > ans) ans = a;
		else if(!freq[ans]) ans--;

		cout << ans << endl;

	}
}
