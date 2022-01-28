#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 99999999
using namespace std;
int Map[51][51];
int Visited[51][51];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int n;
int cnt = 0;
queue<pair<int,int>> que;
void init() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            Visited[i][j] = INF;
    }
}
void bfs(int x, int y) {
    init();
    que.push({x, y});
    Visited[x][y] = 0;
    while (!que.empty()) {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
        for (int i = 0; i < 4; i++) {
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                if (Map[nx][ny]) {
                    if (Visited[nx][ny] > Visited[x][y]) {
                        Visited[nx][ny] = Visited[x][y];
                        que.push({ nx,ny });
                    }
                 
                }
                else {
                    if (Visited[nx][ny] > Visited[x][y] + 1) {
                        Visited[nx][ny] = Visited[x][y] + 1;
                        que.push({ nx,ny });
                    }
                }
            }
        }
    }
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char temp; cin >> temp;
            Map[i][j] = temp - '0';
        }
    }
    bfs(0, 0);
    cout << Visited[n-1][n-1] << "\n";
    return 0;
}