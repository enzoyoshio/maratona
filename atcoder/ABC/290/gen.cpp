#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1])); // atoi(s) converts an array of chars to int
    int n = rand(2, MAXN);
    cout << n << endl;

    for(int i = 0; i < n; ++i) {
	    cout << rand(1, n) << ' ' ;
    }
    cout << endl;
}
