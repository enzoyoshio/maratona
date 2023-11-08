#include <bits/stdc++.h>

using namespace std;
#define int long long

int n;
vector<int> v;

struct median {
	multiset<int> l, r;

	median() {}

	void add(int x) {
		r.insert(x);
		balancear();
	}

	// be sure to always erase elements that are in the sets
	// or else this is not going to work
	void rem(int x) {
		if(l.find(x) != l.end())
			l.erase(l.find(x));
		else
			r.erase(r.find(x));
		balancear();
	}

	void balancear() {

		int n = l.size() + r.size();
		while(l.size() < (n+1)/2 && r.size()) {
			auto el = *r.begin();
			l.insert(el);
			r.erase(r.begin());
		}
		while(l.size() && l.size() > (n+1)/2) {
			auto el = *l.rbegin();
			r.insert(el);
			l.erase(l.find(*rbegin(l)));
		}

		while(l.size() && r.size() && *rbegin(l) > *begin(r)) {
			auto l1 = *rbegin(l), r1 = *begin(r);
			r.erase(begin(r));
			l.erase(prev(end(l)));
			r.insert(l1);
			l.insert(r1);
		}

	}

	int query() { return (l.empty() ? -1 : *l.rbegin());}
};

// essa dp diz qual a maior media que eu posso fazer usando [i..n] 
// dos elementos e respeitando as regras que ele pediu
// e tambem eu tenho que pegar idx
vector<pair<int,int>> tab;
/*
pair<int,int> dp(int idx) {

	if(idx >= n) {
		return {0, 0};
	}

	auto& ans = tab[idx];
	if(~ans.first) return ans;

	auto pula1 = dp(idx+2);
	pula1.first += v[idx];
	pula1.second++;

	auto pula2 = dp(idx+1);
	pula2.first += v[idx];
	pula2.second++;

	if(pula1.first * pula2.second == pula1.second * pula2.first) {
		if(pula2.second > pula1.second) return ans = pula1;
		else retur ans = pula2;
	}

	if(pula1.first *pula2.second > pula1.second * pula2.first) return ans = pula1;
	else return ans = pula2;
}
*/

signed main() {
//	cin.tie(0)->sync_with_stdio(false);

	cin >> n;
	v.resize(n);
	tab.resize(n, {-1, 0});
	for(auto& it: v) cin >> it;

	// apparently this dp works
	// the dp dont works
	cout << fixed << setprecision(15);

	int sumOdd = 0, qtOdd = n/2, sumEven = 0, qtEven = n/2;
	priority_queue<int> posEven, posOdd;
	for(int i = 0; i < n; i++) {
		if(i%2) sumOdd += v[i], posOdd.push(v[i]);
		else sumEven += v[i], posEven.push(v[i]);
	}

	while(posOdd.size()) {
		auto topo = posOdd.top(); posOdd.pop();
		if(sumEven < qtEven * topo) {
			sumEven += topo;
			qtEven++;
		}else break;
	}

	while(posEven.size()) {
		auto topo = posEven.top(); posEven.pop();
		if(sumOdd < qtOdd * topo) {
			sumOdd += topo;
			qtOdd++;
		}else break;
	}

	cout << sumEven << ' ' << qtEven << endl;
	cout << sumOdd << ' ' << qtOdd << endl;
	if(sumEven * qtOdd > qtEven * sumOdd) cout << sumEven/(double)qtEven << endl;
	else cout << sumOdd/(double)qtOdd << endl;

	vector<bool> picked(n, true);
	vector<pair<int,int>> cop(n);
	for(int i = 0; i < n; i++)
		cop[i] = {v[i], i};

	sort(begin(cop), end(cop));

	auto check = [&](int pos) {
		if(pos == 0) {
			return (bool)picked[1];
		}else if(pos == n-1) {
			return (bool)picked[n-2];
		}else {
			return (bool)(picked[pos-1] && picked[pos+1]);
		}
	};

	median m;

	for(int i = 0; i < n; i++) {
		m.add(v[i]);
	}

	for(int i = 0; i < n; i++) {
		int cur = m.query();
		m.rem(cop[i].first);
		if((check(cop[i].second) && m.query() >= cur)) {
			picked[cop[i].second] = false;
		}else {
			m.add(cop[i].first);
		}
	}

	cout << m.query() << endl;
}
