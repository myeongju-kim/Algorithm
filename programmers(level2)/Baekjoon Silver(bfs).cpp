#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int dx[8] = { -2,-2,-1,-1,1,1,2,2 };
int dy[8] = { -1,1,-2,2,-2,2,-1,1 };
void bfs(int n,int x, int y, int c, int d, int mat[301][301], int visited[301][301]) {
	queue<pair<int, int>> que;
	que.push({ x,y });
	visited[x][y] = true;
	while (!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		if (x == c && y == d)break;
		que.pop();
		for (int i = 0; i < 8; i++) {
			int nx = dx[i] + x;
			int ny = dy[i] + y;
			if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny]) {
				visited[nx][ny] = visited[x][y] + 1;
				que.push({ nx,ny });
			}
		}
	}

}

int main() {
	int t; cin >> t;
	for (int u = 0; u < t; u++) {
		int n; cin >> n;
		int mat[301][301] = { 0, };
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int visited[301][301] = { 0, };
		bfs(n,a, b, c, d,mat,visited);
		cout << visited[c][d]-1 << "\n";
		
	}

}
