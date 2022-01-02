#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	priority_queue<int, vector<int>, greater<int>> q;
	int n;
	vector<int> input;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		input.push_back(x);
	}
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == 0) {
			if (q.empty()) cout << 0 << "\n";
			else {
				cout << q.top() << "\n";
				q.pop();
			}
		}
		else {
			q.push(input[i]);
		}
	}
	
	return 0;
}