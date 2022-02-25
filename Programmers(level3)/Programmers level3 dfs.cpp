#include <string>
#include <vector>

using namespace std;
int map[101][101];
vector<int> temp;
void dfs(int v, int* visited, int n) {
    visited[v] = true;
    for (int i = 1; i <= n; i++) {
        if (!visited[i] && map[v][i]) {
            temp.push_back(i);
            dfs(i, visited, n);
        }
    }
}
int solution(int n, vector<vector<int>> r) {
    vector<int> ok;
    for (int i = 0; i < r.size(); i++)
        map[r[i][0]][r[i][1]] = 1;
    for (int i = 1; i <= n; i++) {
        int v[101] = { 0, };
        temp.clear();
        dfs(i, v, n);
        ok.push_back(temp.size());
    }
    for (int i = 0; i < r.size(); i++) {
        map[r[i][0]][r[i][1]] = 0;
        map[r[i][1]][r[i][0]] = 1;
    }
    for (int i = 1; i <= n; i++) {
        int v[101] = { 0, };
        temp.clear();
        dfs(i, v, n);
        ok[i-1]+=temp.size();
    }
    int cnt = 0;
    for (int i = 0; i < ok.size(); i++)
        if (ok[i] == n - 1)cnt++;
    return cnt;
}