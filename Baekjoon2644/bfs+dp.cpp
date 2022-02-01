#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
int map[101][101];
int visited[101];
vector<int> vec;
queue<int> que;
void bfs(int v) {
    visited[v] = 1;
    que.push(v);
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        for (int i = 1; i <= n; i++) {
            if (!visited[i] && map[v][i] == 1) {
                que.push(i);
                visited[i] = visited[v] + 1;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int a, b, k;
    cin >> n >> a >> b >> k;
    for (int i = 1; i <= k; i++) {
        int s, e; cin >> s >> e;
        map[s][e] = 1;
        map[e][s] = 1;
    }
    bfs(a);
    if (!visited[b]) cout << "-1\n";
    else cout << visited[b]-1 << "\n";
    return 0;
}