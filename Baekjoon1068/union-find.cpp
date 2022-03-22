#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int parent[51];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		parent[i] = a;
	}
	int k; cin >> k;
	queue<int> que;
	que.push(k);
	while (!que.empty()) {
		k = que.front();
		parent[k] = -3;
		que.pop();
		for (int i = 0; i < n; i++) {
			if (parent[i] == k) {
				que.push(i);
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int sign = 0;
		if (parent[i] == -3)continue;
		for (int j = 0; j < n; j++) {
			if (i == j)continue;
			if (parent[j] == i) {
				sign = 1;
				break;
			}
		}
		if (sign == 0)cnt++;
	}
	cout << cnt << "\n";
}