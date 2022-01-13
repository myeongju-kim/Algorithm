#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Time {
public:
	int take;
	int end;
	bool operator<(Time& a) {
		return this->end < a.end;
	}
};
int check(vector<Time>& v, int start) {
	int sum = start;
	for (int i = 0; i < v.size(); i++) {
		sum += v[i].take;
		if (sum > v[i].end)return 0;
	}
	return 1;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	vector<Time> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		Time temp;
		cin >> temp.take >> temp.end;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	//int index = -1;
	int i;
	for (i = 0; i <=1000000; i++) {
		if (!check(v, i))break;
	}
	cout << i-1 << "\n";
	return 0;
}