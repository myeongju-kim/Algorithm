#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int parent[222222];
int answer[222222];
int find(int x) {
	if (parent[x] == x) return x;
	else return find(parent[x]);
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		int n; cin >> n;
		int v = 1;
		vector<pair<string, string>> temp;
		map<string, int> m;

		for (int j = 0; j < n; j++) {
			string a, b;
			cin >> a >> b;
			temp.push_back({ a,b });
			if (m[a] == 0) m[a] = v++;
			if (m[b] == 0) m[b] = v++;
		}
		for (int j = 0; j < n*2; j++) {
			parent[j] = j;
			answer[j] = 1;
		}
		for (int j = 0; j < temp.size(); j++) {
			int a = m[temp[j].first]-1;
			int b = m[temp[j].second]-1;
			int pa = find(a);
			int pb = find(b);
			if (pa > pb) {
				int temp = pa;
				pa = pb;
				pb = temp;
			}
			if (pa != pb) {
				parent[pb] = pa;
				answer[pa] += answer[pb];
			}
			cout << answer[pa] << "\n";
		}

		
	}

}