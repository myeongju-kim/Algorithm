#include <iostream>
#include <vector>
using namespace std;

char Mat[101][101];
int N;
int Vis[101][101];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
void dfs(int x, int y, char ch) {
    Vis[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = dx[i] + x;
        int ny = dy[i] + y;
        if (nx >= 0 && nx < N && ny >= 0 && ny < N && !Vis[nx][ny] && Mat[nx][ny]==ch) {
            Vis[nx][ny] = true;
            dfs(nx, ny, ch);
        }
    }
}
void init() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            Vis[i][j] = false;
}
int solve(int blind) {
    int cnt = 0;
    init();
    if (blind) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                if (Mat[i][j] == 'R')Mat[i][j] = 'G';
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!Vis[i][j]) {
                dfs(i, j, Mat[i][j]);
                cnt++;
            }
        }
    }
    return cnt;
}
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cin >> Mat[i][j];
    }
    cout << solve(0) << " ";
    cout << solve(1);

    return 0;
}