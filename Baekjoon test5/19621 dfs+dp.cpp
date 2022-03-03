#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int n;
vector<vector<int>> v;
int max_p = 0;
void dfs(int s, int e, int sum) {
	if (s >= n)return;
	if (v[s][0] < e) return;
	if (max_p < sum) max_p = sum;

	for (int i = s+1; i < n; i++) {
		dfs(i, v[s][1], sum + v[i][2]);
	}

}
bool compare(vector<int> v1, vector<int> v2) {
	if (v1[0] == v2[0]) return v1[1] < v2[1];
	return v1[0] < v2[0];
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b, c; cin >> a >> b >> c;
		v.push_back({ a,b,c });
		
	}
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < n; i++) {
		dfs(i, -1, v[i][2]);
	}
	cout << max_p << "\n";
}