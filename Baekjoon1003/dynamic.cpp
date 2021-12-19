#include <stdio.h>

#define MAX 10000

int main(void) {

	int n = 0;
	int j;
	long long dp[MAX];
	dp[0] = 0;
	dp[1] = 1;
	int arr[MAX];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	for (int i = 0; i < n; i++) {
		if (arr[i] == 0)printf("1 0\n");
		else {
			for (j = 2; j <= arr[i]; j++) {
				dp[j] = dp[j - 1] + dp[j - 2];
			}
			printf("%lld %lld\n", dp[j - 2], dp[j - 1]);
		}
	}
	return 0;

}