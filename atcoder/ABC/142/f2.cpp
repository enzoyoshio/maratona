#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> g[1010], in(1010, 0), pai(1010, -1), h(1010);
bitset<1010> vis;
int ans = -1, len = 0;
int lenAns = 101010;
vector<int> res;

void dfs(int idx, int p=0) {

	pai[idx] = p;
	h[idx] = h[p]+1;
	vis[idx] = true;

	for(auto el: g[idx]) {
		// se eu nao visitei ainda,
		// eh meu filho
//		cout << "=================== " <<  idx << ' ' << el << endl;
		if(!vis[el]) {
			dfs(el, idx);
		}else if(h[el] < h[idx] && abs(h[el]-h[idx]) + 1 < len) {
			//cout << "el = " << el << " idx = " << idx << endl;
			len= abs(h[el]-h[idx]) + 1;
			ans = idx;	
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	cin >> N >> M;
	for(int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		in[b]++;
	}
	
	// tenho que achar o menor ciclo 
	// que tenha no grafo
	//
	// suposed to be easily done with 
	// dfs tree
	// but i dont know if i can do it haha
	

	for(int i = 1; i <= N; i++) {
		vis.reset();
		ans = -1, len = 101010;
		dfs(i);
		
		if(len < lenAns) {
			//			cout << "found one\n";
			res.clear();
			lenAns = len;
			for(int i = 0; i < len; i++) {
				res.push_back(ans); ans = pai[ans];
			}	
		}
	}
	
	if(lenAns == 101010) return cout << -1 << endl, 0;
	
	cout << res.size() << endl;
	for(auto a: res) cout << a << endl;
	
	
}
