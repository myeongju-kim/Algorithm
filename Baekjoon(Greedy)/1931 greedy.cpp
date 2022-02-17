#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}
int main() {
	int n; cin >> n;
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end(), compare);
	int max = 0;
	int end = v[0].second;
	int cnt = 1;
	
	for (int j = 1; j < v.size(); j++) {
		if (v[j].first >= end) {
			cnt++;
			end = v[j].second;
		}
	}
	cout << cnt << "\n";
	
}