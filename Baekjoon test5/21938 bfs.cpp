#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int Map[5000][5000];
int n, m;
int t;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int Visited[5000][5000];
void bfs(int x, int y) {
	queue<pair<int, int>> que;
	que.push({ x,y });
	Visited[x][y] = true;
	while (!que.empty()) {
		x = que.front().first;
		y = que.front().second;
		que.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m*3 && !Visited[nx][ny] && Map[nx][ny] == 255) {
				que.push({ nx,ny });
				Visited[nx][ny] = true;
			}
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m * 3; j++) {
			cin >> Map[i][j];
		}
	}
	cin >> t;
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < m * 3; j++) {
			sum += Map[i][j];
			if ((j + 1) % 3 == 0) {
				if (sum / 3 >= t) {
					Map[i][j] = 255;
					Map[i][j - 1] = 255;
					Map[i][j - 2] = 255;
				}
				else {
					Map[i][j] = 0;
					Map[i][j - 1] = 0;
					Map[i][j - 2] = 0;
				}
				sum = 0;
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m * 3; j++) {
			if (!Visited[i][j] && Map[i][j] == 255) {
				bfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt << "\n";

}