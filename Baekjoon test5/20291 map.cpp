#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	map<string, int> m;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		int index = temp.find('.');
		m[temp.substr(index + 1, temp.size())]++;
	}
	for (auto iter = m.begin(); iter != m.end(); iter++) 
		cout << iter->first << " " << iter->second << "\n";
}