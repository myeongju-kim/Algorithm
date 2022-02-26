#include <string>
#include <vector>

using namespace std;
int map[101][101];
int Cnt = 0;
void dfs(int v, int n, int* vis) {
    vis[v] = true;
    Cnt++;
    for (int i = 1; i <= n; i++)
        if (!vis[i] && map[v][i])
            dfs(i, n, vis);
}
int solution(int n, vector<vector<int>> v) {
    int min=987654321;
    for (int i = 0; i < v.size(); i++) {
        map[v[i][0]][v[i][1]] = 1;
        map[v[i][1]][v[i][0]] = 1;
    }
    for (int i = 0; i < v.size(); i++) {
        map[v[i][0]][v[i][1]] = 0;
        map[v[i][1]][v[i][0]] = 0;
        int vis[101] = { 0, };
        vector<int> temp;
        for (int j = 1; j <= n; j++) {
            if (!vis[j]) {
                Cnt = 0;
                dfs(j, n, vis);
                temp.push_back(Cnt);
            }
        }
        map[v[i][0]][v[i][1]] = 1;
        map[v[i][1]][v[i][0]] = 1;
        if (min > abs(temp[0] - temp[1])) {
            min = abs(temp[0] - temp[1]);
        }
    }
    return min;
}