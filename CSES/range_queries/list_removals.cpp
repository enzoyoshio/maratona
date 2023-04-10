#include <bits/stdc++.h>

using namespace std;

#include <bits/extc++.h>
using namespace __gnu_pbds; // or pb_ds;
template<typename T, typename B = null_type>
using ordered_set = tree<T, B, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;

	ordered_set<pair<int,int>> s;

	for(int i = 0; i < n; i++) {
		int a; cin >> a;
		s.insert({i, a});
	}

	for(int i = 0; i < n; i++) {
		int pos; cin >> pos;
		auto [a, b] = *s.find_by_order(pos-1);
		s.erase(s.find_by_order(pos-1));
		cout << b << ' ';
	}
	cout << endl;
}
