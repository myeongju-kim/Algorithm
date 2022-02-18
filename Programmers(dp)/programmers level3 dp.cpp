#include <string>
#include <vector>

using namespace std;
int dp[501][501];
int solution(vector<vector<int>> t) {
    int answ = 0;
    dp[0][0] = t[0][0];
    for (int i = 1; i < t.size(); i++) {
        for (int j = 0; j < t[i].size(); j++) {
            if (j == 0) dp[i][j] = dp[i - 1][j] + t[i][j];
            else if (j == i)dp[i][j] = dp[i - 1][j - 1] + t[i][j];
            else dp[i][j] = max(dp[i - 1][j - 1] + t[i][j], dp[i - 1][j] + t[i][j]);
        }
    }
    int ans = 0;
    for (int i = 0; i < t[t.size() - 1].size(); i++) {
        if (ans < dp[t.size() - 1][i])
            ans = dp[t.size() - 1][i];
    }
    return ans;
}