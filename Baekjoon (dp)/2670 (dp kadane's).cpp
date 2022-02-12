#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
double item[10000];
double dp[10000];
int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++)
		cin >> item[i];
	dp[0] = item[0];
	double result = -1;
	for (int i = 1; i < n; i++) {
		dp[i]=max(item[i]*dp[i-1], item[i]);
		result = max(result, dp[i]);
	}
	printf("%.3lf", result);
}