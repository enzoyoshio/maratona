#include <bits/stdc++.h>

using namespace std;

struct num {
	int x;
	queue<int> q;

	num() {}
	num(int a, int x): x(x) {
		q.push(a);
	}

	bool canAdd() {
		return x+1 <= q.front();
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t; while(t--) {
		int n;
		cin >> n;
		vector<int> v(n);
		for(auto& it: v)
			cin >> it;
		vector<int> ans(n);
		ans[0] = 1;
		num numero(v[0], 1);

		for(int i = 1; i < n; i++) {
		
			if(numero.canAdd()) {
				numero.x++;
			}else 
				numero.q.pop();
			numero.q.push(v[i]);

			ans[i] = numero.x;	
		}

		for(auto el: ans)
			cout << el << ' ';
		cout << endl;

	}
}
