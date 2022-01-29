#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;
int m, n, k;
int Map[101][101];
int Visited[101][101];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int total = 1;
queue<pair<int, int>> que;
void bfs(int x, int y) {
    que.push({ x,y });
    Visited[x][y] = true;
    while (!que.empty()) {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
        for (int i = 0; i < 4; i++) {
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && !Visited[nx][ny] && !Map[nx][ny]) {
                total++;
                Visited[nx][ny] = true;
                que.push({ nx,ny });
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> m >> n >> k;
    for (int i = 0; i < k; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i = m-y2; i < m-y1; i++) {
            for (int j = x1; j < x2; j++) {
                Map[i][j] = 1;
            }
        }
    }
    int cnt = 0;
    vector<int> ans;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!Visited[i][j] && !Map[i][j]) {
                cnt++;
                bfs(i, j);
                ans.push_back(total);
                total = 1;
            }
        }
    }
    cout << cnt << "\n";
    sort(ans.begin(), ans.end());
    for (auto i = 0; i<ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}