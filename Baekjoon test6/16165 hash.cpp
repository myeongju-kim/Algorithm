#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<string>> girl;
	for (int i = 0; i < n; i++) {
		string group; cin >> group;
		int p; cin >> p;
		vector<string> temp;
		temp.push_back(group);
		for (int j = 0; j < p; j++) {
			string name; cin >> name;
			temp.push_back(name);
		}
		girl.push_back(temp);
	}

	for (int i = 0; i < m; i++) {
		string name; cin >> name;
		int flag; cin >> flag;
		if (flag == 1) {
			for (int j = 0; j < girl.size(); j++) {
				if (find(girl[j].begin(), girl[j].end(), name) != girl[j].end()) {
					cout << girl[j][0] << "\n";
					break;
				}
			}
		}
		else {
			for (int j = 0; j < girl.size(); j++) {
				if (find(girl[j].begin(), girl[j].end(), name) != girl[j].end()) {
					vector<string> temp(girl[j].begin() + 1, girl[j].end());
					sort(temp.begin(), temp.end());
					for (int k = 0; k < temp.size(); k++)
						cout << temp[k] << "\n";
					break;
				}
			}
		}
	}
}