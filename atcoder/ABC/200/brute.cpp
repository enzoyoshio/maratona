#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    for(auto& it: v) cin >> it;
    map<int,int> freq;

    for(int bit = 1; bit < 1 << (n); bit++) {
        int sum = 0;
        for(int i = 0; i < n; i++) {
            if(((bit>>i) & 1) != 0) sum += v[i]; 
        }
//        cout << " ------------------------------------- \n";
//        cout << bitset<10>(bit).to_string() << endl;
//        cout << sum%200 << endl;
        freq[sum%200]++;
    }

    for(auto [a, b]: freq) if(b > 1) return cout << "yes\n", 0;

    cout << "no\n";
}
