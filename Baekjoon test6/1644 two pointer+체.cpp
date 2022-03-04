#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int Pnum[4000001];
void sosu(int n) {
	for (int i = 2; i <= n; i++)
		Pnum[i] = i;
	for (int i = 2; i <= sqrt(n); i++) {
		if (Pnum[i] == 0) continue;
		for (int j = i + i; j <= n; j+=i)
			Pnum[j] = 0;
	}
}
int main() {
	int n;
	cin >> n;
	sosu(n);
	vector<int> v;
	for (int i = 2; i <= n; i++)
		if (Pnum[i] != 0) v.push_back(i);
	int s = 0, e = 0;
	int sum = 0;
	int cnt=0;
	while (1) {
		if (sum == n) cnt++;
		if (sum >= n) sum -= v[s++];
		else if (e == v.size())break;
		else sum += v[e++];
	}
	cout << cnt << "\n";
}