#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
using namespace std;
int Pnum[10000000];
void ache(int n) {
	for (int i = 2; i <= n; i++)
		Pnum[i] = i;
	for (int i = 2; i <= sqrt(n); i++) {
		if (Pnum[i] == 0) continue;
		for (int j = i + i; j <= n; j += i)
			Pnum[j] = 0;
	}
}
int Cnt;
char pArr[10];
map<int, int> Map;
void permutation(string temp, int depth, int r, int n, bool* check) {
	if (depth == r) {
		string str;
		for (int i = 0; i < depth; i++)
			str.push_back(pArr[i]);

		if (Map[stoi(str)]==0 && Pnum[stoi(str)] != 0) Cnt++;
		Map[stoi(str)] = true;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!check[i]) {
			check[i] = true;
			pArr[depth] = temp[i];
			permutation(temp, depth + 1,r,n,check);
			check[i] = false;
		}
	}
}

int main() {
	int n; cin >> n;
	vector<string> t;
	int m = 0;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		if (m < stoi(temp)) m = stoi(temp);
		t.push_back(temp);
	}
	ache(m);
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= t[i].size(); j++) {
			bool check[10] = { 0, };
			permutation(t[i], 0, j, t[i].size(), check);
		}
		cout << Cnt << "\n";
		Cnt = 0;
		Map.clear();
	}
}