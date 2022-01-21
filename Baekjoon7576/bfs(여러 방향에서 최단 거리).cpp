#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;

int N, M;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int Max = 0;
int Mat[1001][1001];
int Visited[1001][1001];
int dp[1001][1001];

int Day = 0;
queue<tuple<int,int,int>> que;

int check() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (Mat[i][j] == 0)return 0;
        }
    }
    return 1;
}
int Is_empty() {
    return 1;
}

void bfs() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (Mat[i][j] == 1) {
                Visited[i][j] = true;
                dp[i][j] = 0;
                que.push(make_tuple(i, j, 0));
            }
        }
    }
    while (!que.empty()) {
        int tx = get<0>(que.front());
        int ty = get<1>(que.front());
        int td = get<2>(que.front());
        que.pop();
        for (int i = 0; i < 4; i++) {
            int nx = tx + dx[i];
            int ny = ty + dy[i];
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && Mat[nx][ny] == 0 && !Visited[nx][ny]) {
                Visited[nx][ny] = true;
                Mat[nx][ny] = 1;
                dp[nx][ny] = td + 1;
                que.push(make_tuple(nx, ny, td + 1));
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> M >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> Mat[i][j];
    bfs();
    if (!check())cout << "-1\n";
    else cout << *max_element(&dp[0][0], &dp[0][0] + 1001*1001) << "\n";
   
    return 0;
}
