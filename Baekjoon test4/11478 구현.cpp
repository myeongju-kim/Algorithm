#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
using namespace std;

int main() {
	string temp;
	cin >> temp;
	set<string> s;
	for (int i = 0; i < temp.size(); i++) {
		for (int j = 0; j < temp.size() - i; j++) {
			string str = temp.substr(j, i+1);
			s.insert(str);
		}
	}
	cout << s.size() << "\n";
}