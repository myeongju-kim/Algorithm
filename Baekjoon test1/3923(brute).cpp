#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

vector<pair<int, int>> vec;
int A;
int B;
void find_front(int a, int b, int c) {
	int tempa = a;
	int cnt_a = 1;
	int cnt_b = 0;
	while (1) {
		tempa += c;
		if (tempa % b == 0) {
			cnt_b = tempa / b;
			break;
		}
		cnt_a++;
		tempa = a * cnt_a;
	}
	vec.push_back({ cnt_a,cnt_b });
}
void find_back(int a, int b, int c) {
	int tempb = b;
	int cnt_a = 0;
	int cnt_b = 1;
	while (1) {
		tempb += c;
		if (tempb % a == 0) {
			cnt_a = tempb / a;
			break;
		}
		cnt_b++;
		tempb = b * cnt_b;
	}
	vec.push_back({ cnt_a,cnt_b });
}
void find_left(int a, int b, int c) {
	int left = c % a;
	if (left % b == 0) vec.push_back({ c / a,left / b });

}
void find_right(int a, int b, int c) {
	int right = c % b;
	if (right % a == 0) vec.push_back({right / a,c / b });
	
}
void find_sum(int a, int b, int c) {
	int temp = c / a;
	int flag = 0;
	for (int i = temp; i >= 1; i--) {
		int sum = i * a;
		for (int j = 1; j <= temp; j++) {
			if (sum + j * b == c) {
				vec.push_back({ i,j });
				flag = 1;
				break;
			}
		}
		if (flag == 1)break;
	}
	temp = c / b;
	flag = 0;
	for (int i = temp; i >= 1; i--) {
		int sum = i * b;
		for (int j = 1; j <= temp; j++) {
			if (sum + j * a == c) {
				vec.push_back({ j,i });
				break;
			}
		}
		if (flag == 1)break;
	}


}
bool compare(pair<int, int> p1, pair<int, int> p2) {
	if (p1.first + p1.second == p2.first + p2.second) 
		return A*p1.first + B*p1.second < A*p2.first + B*p2.second;
	return p1.first + p1.second < p2.first + p2.second;
}
int main() {
	while (1) {
		int a, b, c; cin >> a >> b >> c;
		A = a, B = b;
		if (a == 0 && b == 0 && c == 0)break;
		if (c % a == 0) vec.push_back({ c / a,0 });
		if (c % b == 0) vec.push_back({ 0,c / b });
		find_front(a, b, c);
		find_back(a, b, c);
		if (c > a && c > b) {
			find_left(a, b, c);
			find_right(a, b, c);
			find_sum(a, b, c);
		}
		sort(vec.begin(), vec.end(), compare);
		cout << vec[0].first << " " << vec[0].second << "\n";
		vec.clear();
	}
}