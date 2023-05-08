// generating a random sequence of distinct elements
#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1])); // atoi(s) converts an array of chars to int

    cout << 1 << endl;
    int n = rand(1, 200000);
    int m = rand(1, 1000'000'000);

    cout << n << ' ' << m << endl;

    for(int i = 0; i < n; i++) {
      cout << rand(1, 1000'000'000) << " " << rand(1, 1000'000'000) << endl;
    }
 }
