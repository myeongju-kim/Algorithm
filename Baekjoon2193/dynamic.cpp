#include <stdio.h>
#define MAX 100

int main(void){
	long long dp[MAX];
	int n;
	scanf("%d", &n);
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i < n; i++)
		dp[i] = dp[i - 1] + dp[i - 2];
	printf("%lld", dp[n - 1]);
	return 0;

}​