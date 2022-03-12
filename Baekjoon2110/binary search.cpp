#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, C;
vector<int> home;

int check(int mid) {
	int cnt = 0;
	int cur = -1000000001;
	for (int i = 0; i < home.size(); i++) {
		if (home[i] - cur >= mid) {
			cur = home[i];
			cnt++;
		}
	}
	if (cnt >= C) return 1;
	else return 0;
}
int main() {
	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		int temp; cin >> temp;
		home.push_back(temp);
	}
	sort(home.begin(), home.end());
	int left = 0;
	int right = home.back() - home.front();
	while (left != right) {
		int mid = (left + right + 1) / 2;
		if (check(mid)) left = mid;
		else right = mid - 1;
	}
	cout << left << "\n";
	
}
