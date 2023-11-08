#include <bits/stdc++.h>

using namespace std;

bool bit(int x, int id) {
	return ((1 << id) & x) != 0;
}

int best(vector<int> v, int id=30) {

	if(v.size() == 1) return 0;
	if(id < 0) return 0;

	sort(begin(v), end(v), [&](int a, int b) {
			return bit(a, id) < bit(b, id);
			});

	auto first = bit(v[0], id);
	auto last = bit(v.back(), id);

	if(first == last) {
		return best(v, id-1);
	}

	vector<int> z, o;
	for(auto it: v) {
		if(bit(it, id)) o.push_back(it);
		else z.push_back(it);
	}

	return (1 << id) | min(best(z, id-1), best(o, id-1));
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> v(n);
	for(auto& it: v) cin >> it;

	cout << best(v) << endl;
}
