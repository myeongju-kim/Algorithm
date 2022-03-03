#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <cmath>
using namespace std;
int primeNum[100001];
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
int soin(int n) {
	int s = 2;
	int index = 0;
	if (n % 2 == 0) {
		int tempn = n/2;
		while (1) {
			if (tempn == 1)break;
			if (tempn % s == 0) {
				tempn /= s;
				index++;
			}
			else s++;
		}
		index++;
	}
	else {
		s = 3;
		while (1) {
			if (n == 1)break;
			if (n % s == 0) {
				n /= s;
				index++;
			}
			else s++;
		}
	}
	if (primeNum[index] != 0) return 1;
	return 0;
}
int main() {
	
	int s, e;
	cin >> s >> e;
	int ans = 0;
	sosu(e);
	for (int i = s; i <= e; i++) 
		if (primeNum[i] == 0) 
			ans+=soin(i);
	cout << ans << "\n";
}