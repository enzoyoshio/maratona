#include <bits/stdc++.h>

int main() {

	std::string s = "3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";
	int n;
	std::cin >> n;

	std::cout << s.substr(0, n+2) << std::endl;
}
