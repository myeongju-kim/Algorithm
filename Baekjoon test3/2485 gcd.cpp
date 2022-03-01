#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
	if (a % b == 0) return b;
	if (b % a == 0) return a;
	else return gcd(b, a % b);
}
int main() {
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int temp; cin >> temp;
		v.push_back(temp);
	}
	vector<int> s;
	for (int i = 0; i < n - 1; i++)
		s.push_back(v[i + 1] - v[i]);
	int min = 987654321;
	for (int i = 0; i < s.size()-1; i++) {
		int temp = gcd(s[i], s[i + 1]);
		if (min > temp) min = temp;
	}
	int cnt = 0;
	for (int i = 0; i < n - 1; i++) {
		if (v[i + 1] - v[i] == min)continue;
		else cnt += (v[i + 1] - v[i]) / min - 1;
	}
	cout << cnt << "\n";
}