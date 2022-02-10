#include <vector>
#include <queue>

using namespace std;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
void bfs(int x, int y, int cap, int& cnt, int m, int n, vector<vector<int>> map, int visited[101][101]) {
    queue<pair<int, int>> que;
    que.push({ x,y });
    visited[x][y] = true;
    while (!que.empty()) {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
        for (int i = 0; i < 4; i++) {
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny] && map[nx][ny] == cap) {
                que.push({ nx,ny });
                visited[nx][ny] = true;
                cnt++;
            }
        }
    }
}
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    int visited[101][101]={0,};
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (picture[i][j]>0 && !visited[i][j]) {
                int temp = 1;
                bfs(i, j, picture[i][j], temp, m, n, picture, visited);
                if (max_size_of_one_area < temp)
                    max_size_of_one_area = temp;
                number_of_area++;
            }
        }
    }
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
