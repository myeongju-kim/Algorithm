#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	stable_sort(v.begin(), v.end());
	int k;
	cin >> k;
	int s = 0;
	int e = n - 1;
	int cnt = 0;
	while (1) {
		if (s >= e)break;
		int sum = v[s] + v[e];
		if (sum == k) {
			cnt++;
			s++;
			e--;
		}
		else if (sum > k) e--;
		else s++;
	}
	cout << cnt << "\n";
	
}