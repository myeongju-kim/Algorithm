#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


int n, m;
int sz = 0;
int map[501][501];
int visited[501][501];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
vector<int> vec;
queue<pair<int, int>> que;
void bfs(int x,int y) {
    que.push({ x,y });
    sz++;
    visited[x][y] = true;
    while (!que.empty()) {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
        for (int i = 0; i < 4; i++) {
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && map[nx][ny]) {
                que.push({ nx,ny });
                sz++;
                visited[nx][ny] = true;
            }
        }
    }
  
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
    int cnt = 0;
    int max = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && map[i][j]) {
                bfs(i, j);
                cnt++;
                if (max < sz)
                    max = sz;
                sz = 0;
            }
        }
    }
    cout << cnt << "\n"<<max<<"\n";
    return 0;
}