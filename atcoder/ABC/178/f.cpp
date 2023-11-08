#include <bits/stdc++.h>

using namespace std;
using iii = array<int, 3>;

#define db(x) cerr << "[ " << #x << " = " << x << " ]\n"

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> a(n), b(n), fa(n), fb(n);

	for(auto& it: a) cin >> it, it--, fa[it]++;
	for(auto& it: b) cin >> it, it--, fb[it]++;

	for(int i = 0; i < n; i++)
		if(fa[i] + fb[i] > n)
			return cout << "No\n", 0;	

	if(n == 1) {
		if(a[0] == b[0]) return cout << "No\n", 0;
		return cout << "Yes\n" << b[0]+1 << endl, 0;
	}

	bool can = true;
	for(int i = 0; i < n; i++) {
		can &= a[i] != b[i];
	}

	if(can) {
		cout << "Yes\n";
		for(auto it: b) cout << it+1 << ' ';
		cout << '\n';
		return 0;
	}


	vector<int> ans(n);
	multiset<int> free;
	for(auto it: b) free.insert(it);

	can = true;
	for(int i = 0; i < n; i++) {

		auto el = *rbegin(free);
		free.erase(prev(end(free)));

		/*
		db(i);
		db(el);
		db(a[i]);
		*/

		if(el != a[i]) ans[i] = el;
		else {

			free.insert(el);
			auto el1 = free.lower_bound(el);

			if(el1 == begin(free)) {
				can = false;
				break;
			}
			el1--;

			ans[i] = *el1;
			free.erase(el1);
		}
		
		/*
		db(ans[i]);
		cout << endl << endl;
		*/


	}

	if(!can) {
		free.clear();
		for(auto it: b) free.insert(it);

		for(int i = 0; i < n; i++) {

			auto el = free.upper_bound(a[i]);

			if(el == end(free)) {
				auto el2 = free.lower_bound(a[i]);
				el2--;
				ans[i] = *el2;
				free.erase(el2);
			}else {
				ans[i] = *el;
				free.erase(el);
			}
		}


	}

	cout << "Yes\n";
	for(auto it: ans) cout << it+1 << ' ';
	cout << '\n';
}
