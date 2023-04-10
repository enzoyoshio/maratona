#include <bits/stdc++.h>

//#define int long long

using namespace std;

const int MOD =  1e9+7;

int h, w, k;
vector<vector<vector<int>>> tb(20, vector<vector<int>>(110, vector<int>(20, -1)));

#define db(x) cout << "[ " << #x << " = " << x << " ]\n"

int add(int a, int b) {
	return (a+b)%MOD;
}

int mul(int a, int b) {
	return ((long long)a * (long long)b)%MOD;
}

int fexp(int b, int e) {
    if(e == 0) return 1;

    int x = fexp(b, e/2);
    x = mul(x, x);

    if(e%2) x = mul(x, b);

    return x;
}

int dp2(int stick, int height, int can) {
	
	if(stick < 1 || stick > w) return 0;

	if(height > h) {
		return mul(stick == k, fexp(2, can));
	}	

	auto& ans = tb[stick][height][can];

	if(~ans) return ans;

	int cur = 0;
	if(stick == 1) {
		if(w-3 >= 0)
			cur = dp2(stick+1, height+1, can + w-3);
		else
			cur = dp2(stick+1, height+1, can);

		cur = add(cur, dp2(stick, height+1, can + w-2));
	}else if(stick == w) {
		if(w-3 >= 0)
			cur = dp2(stick-1, height+1, can + w-3);
		else
			cur = dp2(stick-1, height+1, can);

		cur = add(cur, dp2(stick, height+1, can + w-2));
	}else {
		if(w >= 3)
			cur = dp2(stick, height+1, can + w-3);
		else 
			cur = dp2(stick, height+1, can);

		cur = add(cur, dp2(stick+1, height+1, can + (stick + 1 == w ? max(w-3, 0) : max(w-4, 0))));
		cur = add(cur, dp2(stick-1, height+1, can + (stick - 1 == 1 ? max(w-3, 0) : max(w-4, 0))));

	}

	return ans = cur;
	
}

int dp(int stick, int height, int no) {

    if(stick < 1 || stick > w) return 0;
    if(height > h) {
        /*
        cout << "\ndbg\n";
        db(stick);
        db(height);
        db(no);
        */
 //       db( (w-1) * h - no);
 
        return mul((stick == k), fexp(2, (w-1)*h - no));
    }

    auto& ans = tb[stick][height][no];

    if(~ans) return ans;

    int cur = 0;
    if(stick == 1) {
        cur = dp(stick+1, height+1, no+2);
        cur = add(cur, dp(stick, height+1, no+ (w == 1 ? 0 : 1) ));

    }else if(stick == w) {
        cur = dp(stick-1, height+1, no+2);
        cur = add(cur, dp(stick, height+1, no+ (w == 1 ? 0 : 1)));

    }else {
        
	cur = dp(stick, height+1, no+2);
        cur = add(cur, dp(stick+1, height+1, no+2+ (stick+1 == w? 0: 1)));
        cur = add(cur, dp(stick-1, height+1, no+2+ (stick-1 == 1? 0: 1)));
    
    }

    //return cur;
    return ans = cur;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> h >> w >> k;
    if(w == 1)
	    return cout << 1 << endl, 0;
    cout << dp2(1, 1, 0) << endl;
}
