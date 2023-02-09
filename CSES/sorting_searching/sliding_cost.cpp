#include <bits/stdc++.h>
 
#define int long long

using namespace std;
 
struct median {
    multiset<int> left, right;
    int left_sum = 0, right_sum = 0;
 
    void add(int el) {
        left.insert(el);
        left_sum += el;
        balancear();
    }
 
    void remove(int el) {
        // cout << left.size() << ' ' << right.size() << endl;
        if(right.find(el) != right.end()) {
            right.erase(right.find(el));
            right_sum -= el;
        }
        else {
            left_sum -= el;
            left.erase(left.find(el));
        }
        balancear();
    }
 
    void balancear() {
        int tam = (int)left.size() + (int)right.size();
 
        while((int)right.size() < tam/2) {
            right.insert(*left.rbegin());
            right_sum += *left.rbegin();
            left_sum -= *left.rbegin();
            left.erase(left.find(*left.rbegin()));
        }
 
        while(right.size() && (int)left.size() < (tam+1)/2) {
            left.insert(*right.begin());
            left_sum += *right.begin();
            right_sum -= *right.begin();
            right.erase(right.begin());
        }
        
        while(left.size() && right.size() && *left.rbegin() > *right.begin()) {
            int l = *left.rbegin(), r = *right.begin();
            left_sum -= l; left_sum += r;
            right_sum -= r; right_sum += l;
            left.erase(left.find(l)); right.erase(right.find(r));
            left.insert(r); right.insert(l);
        }
        
    }
 
    int get() {
        return *left.rbegin();
    }
    
    void print() {
        for(auto el: left) cout << el << ' ';
        for(auto el: right) cout << el << ' ';
        cout << endl;
    }

    int cost() {
        int mid = get();
        int l = left.size(), r = right.size();

        return l*mid - left_sum + right_sum - r*mid;
    }
};
 
signed main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(auto& it: v) cin >> it;
 
    median m;
 
    for(int i = 0; i < n; i++) {
        m.add(v[i]);
 
        if(i >= k-1) {
            //m.print();
            cout << m.cost() << ' ';
            m.remove(v[i-k+1]);
            
        }
    }
}
