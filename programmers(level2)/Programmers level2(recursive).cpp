#include <string>
#include <vector>

using namespace std;

int dp[1000][1000];
void jegu(int n, int s, int s_i, int o) {
    if (n < 1)return;
    for (int i = s_i; i < s_i + n; i++) {
        dp[i][o] = s++;
    }
    for (int j = o+1; j < n+o; j++)
        dp[n - 1+s_i][j] = s++;
    for (int i = n - 2+s_i; i >= s_i+1; i--) {
        dp[i][i-o] = s++;
    }
    jegu(n - 3, s, s_i + 2, o + 1);

}
vector<int> solution(int n) {
    jegu(n,1,0,0);
    vector<int> answer;
    for(int i=0; i<n; i++)
        for(int j=0; j<=i; j++)
            answer.push_back(dp[i][j]);
    return answer;
}
