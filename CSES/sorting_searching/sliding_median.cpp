#include <bits/stdc++.h>
 
using namespace std;
 
struct median {
    multiset<int> left, right;
 
    void add(int el) {
        left.insert(el);
        balancear();
    }
 
    void remove(int el) {
        // cout << left.size() << ' ' << right.size() << endl;
        if(right.find(el) != right.end()) right.erase(right.find(el));
        else left.erase(left.find(el));
        balancear();
    }
 
    void balancear() {
        int tam = (int)left.size() + (int)right.size();
 
        while((int)right.size() < tam/2) {
            right.insert(*left.rbegin());
            left.erase(left.find(*left.rbegin()));
        }
 
        while(right.size() && (int)left.size() < (tam+1)/2) {
            left.insert(*right.begin());
            right.erase(right.begin());
        }
        
        while(left.size() && right.size() && *left.rbegin() > *right.begin()) {
            int l = *left.rbegin(), r = *right.begin();
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
};
 
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(auto& it: v) cin >> it;
 
    median m;
 
    for(int i = 0; i < n; i++) {
        m.add(v[i]);
 
        if(i >= k-1) {
            //m.print();
            cout << m.get() << ' ';
            m.remove(v[i-k+1]);
            
        }
    }
}
