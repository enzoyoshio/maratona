#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5+8;
int n, q;
vector<set<int>> st(4*MAXN);
vector<int> v(MAXN);


int main() {
	cin.tie(0)->sync_with_stdio(false);

	cin >> n >> q;
	for(int i = 0; i < n; i++)
		cin >> v[i];

	for(int i = 0; i < q; i++) {
		int a, b; cin >> a >> b;
		a--, b--;
	}
}
