#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <cmath>
#include <queue>
using namespace std;
int N, M;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int Map[55][55];
int xmax = 0;
int ymax = 0;
void bfs(int x, int y, int Visited[55][55]) {
	queue<pair<int, int>> que;
	que.push({ x,y });
	Visited[x][y] = 1;
	xmax = x;
	ymax = y;
	while (!que.empty()) {
		x = que.front().first;
		y = que.front().second;
		que.pop();
		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + x;
			int ny = dy[i] + y;
			if (nx >= 0 && nx < N && ny >= 0 && ny < M && !Visited[nx][ny] && Map[nx][ny] != 0) {
				que.push({ nx, ny });
				Visited[nx][ny] = Visited[x][y] + 1;
				xmax = nx;
				ymax = ny;
			}
		}
	}
}
bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) return a.second > b.second;
	return a.first > b.first;
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> Map[i][j];
	vector<pair<int,int>> msum;
	int mwih = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int Visited[55][55] = { 0, };
			if (Map[i][j] != 0) {
				bfs(i, j, Visited);			
				if (mwih<=Visited[xmax][ymax]) {
					msum.push_back({ mwih,Map[i][j] + Map[xmax][ymax] });
					mwih = Visited[xmax][ymax];
				}
			}
		}
	}
	sort(msum.begin(), msum.end(),compare);
	cout << msum[0].second << "\n";
}
