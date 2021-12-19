#include <stdio.h>
#define MAX 1000

long long pado(int n) {
	long long dp[MAX];
	int i;
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 2;
	dp[4] = 2;
	if (n <= 5) i = n;
	else {
		for (i = 5; i < n; i++)
			dp[i] = dp[i - 1] + dp[i - 5];
	}
	return dp[i - 1];
}

int main(void) {
	int n;
	int arr[MAX];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		arr[i] = a;
	}
	for (int i = 0; i < n; i++)
		printf("%lld\n", pado(arr[i]));
	return 0;
}