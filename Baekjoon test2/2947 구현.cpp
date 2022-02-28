#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

void display(vector<int> v) {
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
}
int main() {
	vector<int> v(5);
	for (int i = 0; i < 5; i++) cin >> v[i];
	while (1) {
		int flag = 0;
		for (int i = 0; i < 5; i++) {
			if (v[i] != i + 1) {
				flag = 1;
				break;
			}
		}
		if (flag == 0)break;
		for (int i = 0; i < 4; i++) {
			if (v[i] > v[i + 1]) {
				int temp = v[i];
				v[i] = v[i + 1];
				v[i + 1] = temp;
				display(v);
			}
		}
	}

}