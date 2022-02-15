#include <string>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
vector<pair<int, int>> point;
void bfs(int x,int y, int visited[5][5], char mat[5][5]) {
    queue<pair<int, int>> que;
    visited[x][y] = true;
    que.push({ x,y });
    while (!que.empty()) {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
        for (int i = 0; i < 4; i++) {
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5 && !visited[nx][ny]) {
                if (mat[nx][ny] !='X') {
                    if (mat[nx][ny] == 'P') point.push_back({ nx,ny });
                    visited[nx][ny] = visited[x][y] + 1;
                    que.push({ nx,ny });
                }
            }
        }
    }
}
vector<int> solution(vector<vector<string>> v) {
    vector<int> answer;
    char mat[5][5];
    for(int a=0; a<v.size(); a++){
        for (int i = 0; i < v[a].size(); i++) {
            for (int j = 0; j < v[a][i].size(); j++)
                mat[i][j] = v[a][i][j];
        }
        int sign = 0;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (mat[i][j] == 'P') {
                    int visited[5][5]={0,};
                    point.clear();
                    bfs(i, j,visited, mat);
                    for (int k = 0; k < point.size(); k++) {
                        int x = point[k].first;
                        int y = point[k].second;
                        if (visited[x][y] - visited[i][j] <= 2 && abs(i-x)+abs(j-y)<=2) {
                            sign=1;
                        }
                    }
                }
            }
        }
        if(sign==1) answer.push_back(0);
        else answer.push_back(1);
    }


    return answer;
}