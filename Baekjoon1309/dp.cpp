#include <iostream>
using namespace std;
#define MAX 100000

int main() {
	int dp[MAX];
	int n;
	cin >> n;
	dp[0] = 3;
	dp[1] = 7;
	for (int i = 2; i < n; i++)
		dp[i] = (dp[i - 2] + dp[i - 1] * 2)%9901;
	cout << dp[n - 1];
	return 0;
}