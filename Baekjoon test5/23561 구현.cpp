#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n*3; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	vector<int> mid;
	int cnt = 0;
	for (int i = 0; i < v.size(); i++) {
		if (cnt == 1) {
			mid.push_back(v[i]);
		}
		if ((i + 1) % n == 0)cnt++;
	}
	cout << mid.back() - mid.front();

	
}