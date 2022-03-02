#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;

int dp[1000001];
int main() {
	dp[0] = 1;
	for(int i=1; i<= 1000000; i++){
		int oi = floor(i - sqrt(i));
		int ti = floor(log(i));
		int thi = floor(i * sin(i) * sin(i));
		dp[i] = (dp[oi] + dp[ti] + dp[thi])%1000000;
	}
	while (1) {
		int n;
		cin >> n;
		if (n == -1)break;
		cout << dp[n] << "\n";
	}
}