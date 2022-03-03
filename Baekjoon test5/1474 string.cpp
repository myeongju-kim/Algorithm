#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, len;
	cin >> n >> len;
	vector<string> v;
	int sum_len = 0;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		sum_len += temp.size();
		v.push_back(temp);
	}
	sum_len = len - sum_len;
	int one_len = (sum_len) / (n - 1);
	int two_len = (sum_len) % (n - 1);
	vector<string> t;
	for (int i = 0; i < two_len; i++) {
		string temp;
		for (int j = 0; j <= one_len; j++) temp.push_back('_');
		t.push_back(temp);
	}
	for (int i = 0; i < n - two_len - 1; i++) {
		string temp;
		for (int j = 0; j < one_len; j++) temp.push_back('_');
		t.push_back(temp);
	}
	cout << v.front();
	for (int i = 1; i < v.size(); i++) {
		if (v[i][0] >= 'A' && v[i][0] <= 'Z') {
			cout << t.back() << v[i];
			t.erase(--t.end());
		}
		else {
			cout << t.front() << v[i];
			t.erase(t.begin());
		}
	}
}