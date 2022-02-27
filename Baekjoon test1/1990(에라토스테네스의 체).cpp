#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
int primeNum[20000000];
void sosu(int n) {
	for (int i = 2; i <= n; i++) {
		primeNum[i] = i;
	}
	for (int i = 2; i <= sqrt(n); i++) {
		if (primeNum[i] == 0)
			continue;
		for (int j = i + i; j <= n; j += i)
			primeNum[j] = 0;
	}
}
int pali(int n) {
	string a = to_string(n);
	string temp(a.rbegin(), a.rend());
	return a == temp;
}
int main() {
	int s, e; cin >> s >> e;
	if (e >= 10000000) e = 10000000;
	sosu(e);
	for (int i = s; i <= e; i++) {
		if (primeNum[i] != 0) {
			if (pali(i)) 
				cout << i << "\n";
		}
	}
	cout << -1;
}