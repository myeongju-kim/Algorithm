#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	string n; cin >> n;
	int s = 1;
	while (1) {
		string begin;
		string temp;
		string end;
		for (int i = 0; i < s; i++)
			temp.push_back(n[i]);
		begin = temp;
		end = temp;
		int a = stoi(temp);
		while (temp.size() < n.size()) {
			a++;
			temp += to_string(a);
			end = to_string(a);
		}
		if (temp == n) {
			cout << begin << " " << end;
			break;
		}
		s++;
	}
}