#include <iostream>
#include <vector>

using namespace std;

int day, tteok;
int dp[100001];
int fibo(int n, int o, int t) {
    dp[1] = o;
    dp[2] = t;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> day >> tteok;
    for (int i = 1; i <= tteok; i++) {
        for (int j = 1; j <= tteok; j++) {
            if (fibo(day, i, j) == tteok) {
                cout << i << "\n" << j;
                return 0;
            }
        }
    }



    return 0;
}