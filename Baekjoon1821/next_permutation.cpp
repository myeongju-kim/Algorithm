#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find(vector<int> v, int n) {
	int sum = 0;
	int count = 1;
	while (v.size() > 1) {
		if (count == n) {
			v.erase(v.begin());
			n--;
			count = 1;
			continue;
		}
		sum = v[0] + v[1];
		v.push_back(sum);
		v.erase(v.begin());
		count++;
	}
	return sum;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, f;
	vector<int> v;
	cin >> n >> f;
	for (int i = 1; i <= n; i++)
		v.push_back(i);
	
	do {
		if (f == find(v,n))break;
	} while (next_permutation(v.begin(), v.end()));

	for (int i = 0; i < n; i++)
		cout << v[i] << " ";


	return 0;
}