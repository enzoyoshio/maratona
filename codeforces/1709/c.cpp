#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#define int long long
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)

#define db(x) cerr << "[ " << #x << " = " << x << " ]\n"

auto main() -> signed {
	fastio;

	int t; cin >> t; while(t--) {
		string s;
		cin >> s;

		int open = 0, close = 0, falta = 0;
		for(auto ch: s)
			open += ch == '(', close += ch == ')', falta += ch == '?';

		int n = s.size();

		int needOpen = max(0LL, close-open); 
		int needClose = max(0LL, open-close);

		/*
		db(needOpen);
		db(needClose);
		*/
	
		falta -= needOpen;
		falta -= needClose;

		needOpen += falta/2;
		needClose += falta/2;

		/*
		db(needOpen);
		db(needClose);
		db(falta);
		*/

		vector<int> opens, closes;
		for(int i = 0; i < n; i++) {
			if(s[i] != '?') continue;

			if(needOpen) {
				opens.emplace_back(i);
				s[i] = '(';
				needOpen--;
			}else {
				closes.emplace_back(i);
				s[i] = ')';
			}

		}

		/*
		cout << "before swapping\n";
		db(s);
		*/

		bool can2 = true;
		if(opens.size() && closes.size()) {
			s[opens.back()] = ')';
			s[closes[0]] = '(';
		}
		else can2 = false; // se eu nao conseguir trocar, entao so tem um jeito de fazer um rbs

		/*
		cout << "after swapping\n";
		db(s);
		*/

		// testar aqui 

		int pilha = 0;
		for(auto ch: s) {
			if(ch == '(') pilha++;
			else pilha--;

			if(pilha < 0) can2 = false;
		}

		if(pilha) can2 = false;


		if(can2) cout << "No\n";
		else cout << "Yes\n";

	}
}

