#include <iostream>
#include <vector>
using namespace std;

int primeNum[50001];
void sosu(int n) {
	for (int i = 2; i <= n; i++){
		primeNum[i] = i;
	}
	for (int i = 2; i <= sqrt(n); i++){
		if (primeNum[i] == 0)
			continue;
		for (int j = i + i; j <= n; j += i)
			primeNum[j] = 0;
	}
}

int main() {
	int t;
	cin >> t;
	for (int k = 0; k < t; k++) {
		vector<int> v;
		int n; cin >> n;
		int dif = 99999;
		int a, b;
		sosu(n);
		for (int i = 2; i <= n; i++) {
			if (primeNum[i] != 0)
				v.push_back(i);
		}
		for (int i = 0; i < v.size(); i++) {
			for (int j = i; j < v.size(); j++) {
				if (v[i] + v[j] == n && dif > v[j] - v[i]) {
					dif = v[j] - v[i];
					a = v[i];
					b = v[j];
				}
			}
		}
		cout << a << " " << b << "\n";
	}
	
	return 0;
}