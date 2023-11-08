// generating a random sequence of distinct elements
#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1])); // atoi(s) converts an array of chars to int
    int n = rand(2, 15);
    printf("%d\n", n);
    int last = 1;

    for(int i = 0; i < n; ++i) {
	int novo = rand(last, n);
	printf("%d ", novo);
	last = novo;
    }
    puts("\n");

    last = 1;
    for(int i = 0; i < n; ++i) {
	int novo = rand(last, n);
	printf("%d ", novo);
	last = novo;
    }
    puts("\n");
}
