#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int Max = 0;
void dfs(vector<vector<int>>& mat, vector<vector<int>> visited, int x, int y) {
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = dx[i] + x;
        int ny = dy[i] + y;
        if (nx >= 0 && nx < N && ny >= 0 && ny < M && mat[nx][ny] == 0 && !visited[nx][ny]) {
            mat[nx][ny] = 2;
            dfs(mat, visited, nx, ny);
        }
    }
}
void wall(vector<vector<int>> mat, vector<vector<int>> visited, int x, int y, int cnt) {
    mat[x][y] = 1;
    if (cnt >= 2) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (mat[i][j] == 2) {
                    dfs(mat, visited, i, j);
                }
            }
        }
        int temp = 0;
        for(int i=0; i<N; i++)
            temp+=count(mat[i].begin(), mat[i].begin()+M,0);
        if (Max < temp)
            Max = temp;
        return;
    }
    for (int i = x; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i == x && j < y)continue;
            if (mat[i][j] == 0) {
                wall(mat, visited, i, j, cnt+1);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vector<vector<int>> mat(8, vector<int>(8, 0));
    vector<vector<int>> visited(8, vector<int>(8, 0));
    cin >> N >> M;
    int sign = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) cin >> mat[i][j];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if(mat[i][j]==0)
                wall(mat,visited, i, j, 0);
        }
    }
    cout << Max << "\n";
    return 0;
}
