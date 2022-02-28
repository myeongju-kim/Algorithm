#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;


int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	int flag = 1;
	while (next_permutation(v.begin(), v.end())) {
		flag = 0;
		for (int i = 0; i < n; i++)
			cout << v[i] << " ";
		break;
	}
	if (flag) cout << -1;
	
}