#include <iostream>
#include <queue>
#define INF 9999999
using namespace std;

int n, m;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int visited[101][101];
int map[101][101];
queue <pair<int, int>> que;
void bfs(int x, int y) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            visited[i][j] = INF;
    }
    visited[x][y] = 0;
    que.push({ x,y });
    while (!que.empty()) {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
        for (int i = 0; i < 4; i++) {
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (!map[nx][ny]) {
                    // 최단경로 갱신
                    if (visited[nx][ny] > visited[x][y]) {
                        visited[nx][ny] = visited[x][y];
                        que.push({ nx,ny });
                    }
                }
                else {
                    // 벽을 하나 깨는 것으로 +1
                    if (visited[nx][ny] > visited[x][y] + 1) {
                        visited[nx][ny] = visited[x][y] + 1;
                        que.push({ nx,ny });
                    }
                }
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char temp;
            cin >> temp;
            map[i][j] = temp - '0';
        }
    }
    bfs(0, 0);
    cout << visited[n - 1][m - 1] << "\n";

    return 0;
}