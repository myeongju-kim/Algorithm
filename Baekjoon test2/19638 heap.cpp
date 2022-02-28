#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;


int main() {
	priority_queue<int> pq;
	int n, h, k;
	cin >> n >> h >> k;
	for (int i = 0; i < n; i++) {
		int temp; cin >> temp;
		pq.push(temp);
	}
	int cnt = 0;
	int sign = 0;
	while (!pq.empty()) {
		if (pq.top() < h) {
			sign = 1;
			break;
		}
		if (cnt >= k)break;
		int value = floor(pq.top() / 2.0);
		if (value == 0) {
			cnt++;
			continue;
		}
		pq.pop();
		pq.push(value);
		cnt++;
	}
	if (sign == 1) {
		cout << "YES\n" << cnt;
	}
	else {
		cout << "NO\n" << pq.top();
	}

}