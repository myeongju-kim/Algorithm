#include <stdio.h>
#include <string.h>
#define MAX 1001
#define Max(X,Y) (X>Y ? X : Y)
int dp[MAX][MAX];

int main(void) {

	char str1[MAX];
	char str2[MAX];
	scanf("%s %s", str1, str2);
	for (int i = 1; i <= strlen(str1); i++) {
		int n = 0;
		for (int j = 1; j <= strlen(str2); j++) {
			if (str1[i - 1] == str2[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = Max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	printf("%d", dp[strlen(str1)][strlen(str2)]);
	return 0;
}