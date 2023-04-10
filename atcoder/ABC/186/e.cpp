#include <bits/stdc++.h>

#define int long long

using namespace std;

int inv(int i, int m) {
  return i <= 1 ? i : m - (long long)(m/i) * inv(m % i, m) % m;
}

int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t; while(t--) {
		int n, s, k;
		cin >> n >> s >> k;

		int g = gcd(gcd(n, s), k);
		n /= g, s /= g, k /= g;

		if(gcd(k, n) != 1) {
			cout << -1 << endl;
			continue;
		}

		int x, y;
		gcd(k, n, x, y);
		cout << ((x%n+n)%n * (n-s) )%n<< endl;
	}
}
