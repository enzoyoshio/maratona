#include <bits/stdc++.h>

using namespace std;

struct DSU {
	vector<int> pai, tam;
	int n;

	DSU(int n) : n(n), pai(n), tam(n, 2) {
		iota(begin(pai), end(pai), 0);
	}

	int find(int x) { return x == pai[x] ? x : pai[x] = find(pai[x]);}

	void join(int x, int y) {
		int novox = find(x), novoy = find(y);
		if(novox == novoy) {
			return;
		}

		if(tam[novox] > tam[novoy]) swap(novox, novoy);
		pai[novox] = novoy;
		tam[novoy] += tam[novox];
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, k, l;
	cin >> n >> k >> l;

	DSU rail(n), road(n);
	for(int i = 0; i < k; i++) {
		int a, b; cin >> a >> b; a--, b--;
		rail.join(a, b);
	}

	for(int j = 0; j < l; j++) {
		int a, b; cin >> a >> b; a--, b--;
		road.join(a, b);
	}

	map<pair<int,int>, int> sset;

	for(int i = 0; i < n; i++)
		sset[{rail.find(i), road.find(i)}]++;

	for(int i = 0; i < n; i++)
		cout << sset[{rail.find(i), road.find(i)}] << ' ';
	cout << endl;
}
