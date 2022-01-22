#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Bag {
    int value;
    int weight;
};
int dp[102][100002];
Bag b[102];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        Bag temp;
        cin >> temp.weight >> temp.value;
        b[i] = temp;
    }
    for (int i = 1; i <= n; i++) {
        int val=b[i].value;
        int we=b[i].weight;
        // j는 무게를 의미 0~k까지의 무게
        for (int j = 0; j <= k; j++) {
            //넣으려는 weight이 j보다 큰 경우는 담지 않는다.
            if (j < we) dp[i][j] = dp[i - 1][j];
            // 그 외의 경우
            else dp[i][j] = max(val + dp[i - 1][j - we], dp[i - 1][j]);
        }
    }
    cout << dp[n][k] << "\n";
    return 0;
}
