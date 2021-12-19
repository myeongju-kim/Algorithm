#include <stdio.h>
#define MAX 10001

int main(void) {
	int n;
	long long dp[MAX];
	scanf("%d", &n);
	dp[0] = 1;

	for (int i = 1; i <= n; i++) {
		if (i % 2 == 0) {
			dp[i] = (dp[i - 1] * 2 + 1) % 10007;
		}
		else {
			dp[i] = (dp[i - 1] * 2 - 1) % 10007;
		}
	}
	printf("%lld", dp[n]);
	return 0;
}