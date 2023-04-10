#include <bits/stdc++.h>

using namespace std;

#include <bits/extc++.h>
using namespace __gnu_pbds; // or pb_ds;
template<typename T, typename B = null_type>
using ordered_set = tree<T, B, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

using tiii = tuple<int,int,int>;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n;
    cin >> n;
    vector<tuple<int,int,int>> v;
    vector<int> contains(n, 0), contained(n, 0);
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        v.emplace_back(a, b, i); 
    }
    sort(v.begin(), v.end(), [](tiii a, tiii b) {
	auto [a1, a2, aid] = a;
	auto [b1, b2, bid] = b;

	return a1 < b1 || (a1 == b1 && a2 > b2);
    });

    ordered_set<pair<int,int>> pos;
    for(auto [left, right, id]: v) {
	auto p = pos.order_of_key(make_pair(right, -1));
	contained[id] = (int)pos.size() - p;
	pos.insert(make_pair(right, id));
    }

    pos.clear();
    reverse(v.begin(), v.end());

    for(auto [left, right, id]: v) {
	auto p = pos.order_of_key(make_pair(right+1, -1));
	contains[id] = p;
	pos.insert(make_pair(right, id));
    }

    for(auto it: contains)
	    cout << it << ' ';
    cout << endl;

    for(auto it: contained)
	    cout << it << ' ';
    cout << endl;
}
