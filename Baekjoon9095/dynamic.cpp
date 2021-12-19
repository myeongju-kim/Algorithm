#include <stdio.h>
int find(int* dp, int num) {
	dp[0] = 1;
	dp[1] = 2;
	dp[2] = 4;
	if (num <= 3)
		return dp[num - 1];
	int i;
	for (i = 3; i < num; i++)
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	return dp[i - 1];
}

int main(void) {
	int n;
	int arr[100000];
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	for (int i = 0; i < n; i++) {
		int dp[100000] = { 0 };
		printf("%d\n", find(dp, arr[i]));
	}
	return 0;

}