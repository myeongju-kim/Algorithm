#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	queue<int> que;
	vector<int> res;
	for (int i = 0; i < n; i++) {
		string t;
		int a;
		cin >> t;
		if (t == "push") {
			cin >> a;
			que.push(a);
		}
		else if (t == "front") {
			if (que.empty()) res.push_back(-1);
			else res.push_back(que.front());
		}
		else if (t == "back") {
			if (que.empty()) res.push_back(-1);
			else res.push_back(que.back());
		}
		else if (t == "size") res.push_back(que.size());
		else if (t == "empty") {
			if (que.empty()) res.push_back(1);
			else res.push_back(0);
		}
		else if (t == "pop") {
			if (que.empty())res.push_back(-1);
			else {
				res.push_back(que.front());
				que.pop();
			}
		}
	}
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << "\n";
}