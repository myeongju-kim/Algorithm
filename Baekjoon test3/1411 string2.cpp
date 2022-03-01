#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int check(string a, string b) {
	for (int i = 0; i < a.size(); i++) {
		if (a[i] != b[i]) {
			if (find(a.begin(), a.end(), b[i]) != a.end()) {
				char temp = a[i];
				for (int j = 0; j < a.size(); j++) {
					if (a[j] == temp) a[j] = b[i];
					else if (a[j] == b[i]) a[j] = temp;
				}

			}
			else {
				char temp = a[i];
				for (int j = 0; j < a.size(); j++)
					if (a[j] == temp) a[j] = b[i];
			}
		}
	}
	return a == b;
}
int main() {
	int n;
	cin >> n;
	vector<string> v;
	for (int i = 0; i < n; i++) {
		string temp; cin >> temp;
		v.push_back(temp);
	}
	int cnt = 0;
	for (int i = 0; i < v.size(); i++) {
		for (int j = i+1; j < v.size(); j++) {
			if (i == j)continue;
			if (check(v[i], v[j])) cnt++;
		}
	}
	cout << cnt << "\n";
}