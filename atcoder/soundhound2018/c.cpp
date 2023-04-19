#include <bits/stdc++.h>

using namespace std;

int main() {
	long long n, m, d;
	cin >> n >> m >> d;

	cout << fixed << setprecision(12);
	if(d == 0) 
		cout << (double)(m-1)/n << endl;
	else 
		cout << (double)(2*(n-d) * (m-1))/(n*n) << endl;
}
