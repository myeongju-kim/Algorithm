#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define ll long long 
using namespace std;

ll s, k;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> s >> k;
	if (s % k == 0) {
		cout << fixed;
		cout.precision(0);
		cout << pow(s / k, k) << "\n";
		return 0;
	}
	ll val = s / k; //2
	ll dump = s % k; //2
	ll m = 1;
	int count = 1;
	for (int i = 1; i <= k; i++) {
		if (count <= dump) m *= (val + 1);
		else m *= val;
		count++;
	}
	cout << fixed;
	cout.precision(0);
	cout << m << "\n";
	return 0;
}