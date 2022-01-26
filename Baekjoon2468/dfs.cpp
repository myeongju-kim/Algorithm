#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n;
int mat[101][101];
int cpy[101][101];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void dfs(int x,int y, int visited[101][101] ) {
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = dx[i] + x;
        int ny = dy[i] + y;
        if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny] && cpy[nx][ny]!=-1)
            dfs(nx, ny,visited);
    }
}
int check(int visited[101][101]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (visited[i][j] == 0)return 0;
    return 1;
}
int main() {
    cin >> n;
    int hmax = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
            if (hmax < mat[i][j])
                hmax = mat[i][j];
        }
    }
    int max = 0;
    for (int k = 0; k <= hmax; k++) {
        int visited[101][101] = { 0, };
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] <= k) cpy[i][j] = -1;
                else cpy[i][j] = mat[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (cpy[i][j] != -1 && !visited[i][j]) {
                    dfs(i, j,visited);
                    cnt++;
                }
            }
        }
        if (max < cnt)
            max = cnt;
    }
    cout << max << "\n";
    return 0;
}