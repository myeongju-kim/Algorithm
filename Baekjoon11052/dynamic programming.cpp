#include <iostream>
#include <vector>
#define MAX(X,Y) (X)>(Y)?(X):(Y)
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> p(n+1);
	int dp[1001];
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		p[i]= a;
	}
	dp[1] = p[1];
	for (int i = 1; i <= n; i++) {
		dp[i] = p[i];
		for (int j = 1; j < i; j++) {
			dp[i] = MAX(dp[i - j] + dp[j], dp[i]);
		}
	}
	cout << dp[n] << endl;
	return 0;
}