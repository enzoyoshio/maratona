// generating a random sequence of distinct elements
#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1])); // atoi(s) converts an array of chars to int
    int n = rand(2, 10);
    cout << 1 << endl;
    cout << n << endl;
    int cur = 0;
    vector<int> a;
    for(int i = 0; i < n; ++i) {
      cur = rand(cur, 100);
      cout << cur << ' '; 
      a.push_back(cur);
    }
    cout << endl;
    cur = 0;
    for(int i = 0; i < n; i++) {
      cur = rand(max(cur, a[i]), 100);
      cout << cur << ' ';
    }
    cout << endl;
}
