#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5;
int n;
vector<int> v, ord, st(4*MAXN, 0);

int find(int x) {
	return lower_bound(ord.begin(), ord.end(), x) - ord.begin();
}

void update(int idx, int val, int sti=1, int stl=0, int str=n-1) {
	if(idx > str || idx < stl) return;
  
  	if(stl == str) {
		st[sti] = val;
      	return;
    }
  
  	int mid = (stl+str) >> 1, e = sti << 1, d = (sti << 1) + 1;
  
  	update(idx, val, e, stl, mid);
  	update(idx, val, d, mid+1, str);
  
  	st[sti] = max(st[e], st[d]);
}

int query(int A, int B, int sti=1, int stl=0, int str=n-1) {
	if(A > B) return 0;
  
  	if(A > str || B < stl) return 0;
  
  	if(A <= stl && str <= B) return st[sti];
  
  	int mid = (stl+str) >> 1, e = sti << 1, d = (sti << 1) + 1;
  
    return max(query(A, B, e, stl, mid), query(A, B, d, mid+1, str)); 
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
  
  	cin >> n;
  	v.assign(n, 0);
  	for(auto& it: v) cin >> it, it = -it, ord.push_back(it);
  	sort(ord.begin(), ord.end());
  
  	for(auto& it: v) it = find(it);
  
  	int ans = 0;
  
  	for(int i = 0; i < n; i++) {
		int cur = query(0, v[i]);
		update(v[i], cur+1);
		ans = max(ans, query(0, n-1));
	}
  
	cout << ans << endl;
}
