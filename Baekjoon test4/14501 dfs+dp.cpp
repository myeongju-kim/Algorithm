#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
vector<pair<int, int>> v;
int n;
int m = 0;
void dfs(int s, int sum, int tmp) {
	if (s > n) {
		if(s!=n+1) sum -= tmp;
		if (m < sum)m = sum;
		return;
	}
	for (int i = s; i <= n; i++) {
		dfs(v[i].first + i, sum + v[i].second, v[i].second);
	}

}
int main() {
	cin >> n;
	v.push_back({ 0,0 });
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		v.push_back({ a,b });
	}
	dfs(1, 0,0);
	cout << m << "\n";
}