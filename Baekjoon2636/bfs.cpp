#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n,m;
int mat[101][101];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
queue<pair<int,int>> que;
void bfs(int x, int y,int visited[101][101]) {
    visited[x][y] = true;
    que.push({x, y});
    while (!que.empty()) {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
        for (int i = 0; i < 4; i++) {
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            if (!visited[nx][ny] && !mat[nx][ny] && nx >= 0 && nx < n && ny >= 0 && ny < m) {
                que.push({ nx,ny });
                visited[nx][ny] = true;
            }
        }
    }
}
int check() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            if (mat[i][j] != 0)return 0;
    }
    return 1;
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];
    int sign = 0;
    int total = 0;
    int cnt = 0;
    int A = 0;
    while (1) {
        cnt = 0;
        int visited[101][101] = { 0, };
        bfs(0, 0,visited);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1) {
                    for (int a = 0; a < 4; a++) {
                        int nx = i + dx[a];
                        int ny = j + dy[a];
                        if (visited[nx][ny]) {
                            mat[i][j] = 0;
                            cnt++;
                            break;
                        }
                    }
                }
            }
        }
        total++;
        if (check())break;
    }
    cout << total << "\n" << cnt << "\n";
    return 0;
}