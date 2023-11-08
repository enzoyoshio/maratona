#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MOD = 998244353;
const int oo = MOD;

int add(int a, int b) { return (a+b)%MOD;}

int f(int idx, int qt) {

	if(idx >= n)
		return qt * oo;


	int npega = f(idx+1, qt);

	int pega = 0;
	if(qt >= v[idx]) {
		pega = 1 + f(idx+1, qt-v[idx]);
		if(pega < MOD) {



		}else pega = 0; 
	}
	return add(pega, npega);
}

signed main() {

}
