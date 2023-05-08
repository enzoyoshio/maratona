// generating a random sequence of distinct elements
#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1])); // atoi(s) converts an array of chars to int
    int n = rand(2, 10000);
    cout << 1 << endl << n << endl;
    int last = 0;
    for(int i = 0; i < n; ++i) {
	    int cur = rand(last, (int)5e5);
	    cout << cur << ' ';
	    last = cur;
    }
    cout << endl;
}
