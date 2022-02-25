#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int Map[1111][1111];
int Visited1[1111][1111];
int Visited2[1111][1111];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int N, M;
void bfs(int x1, int y1, int x2, int y2) {
	queue<pair<int, int>> que1;
	Visited1[x1][y1]=1;
	queue<pair<int, int>> que2;
	Visited2[x2][y2]= 1;
	que1.push({ x1,y1 });
	que2.push({ x2,y2 });
	int start = 2;
	while (!que1.empty() && !que2.empty()) {
		vector<pair<int, int>> temp1;
		vector<pair<int, int>> temp2;
		while (!que1.empty()) {
			x1 = que1.front().first;
			y1 = que1.front().second;
			if (Visited1[x1][y1] == start)break;
			que1.pop();
			if (Map[x1][y1] == 3) continue;
			for (int i = 0; i < 4; i++) {
				int nx = dx[i] + x1;
				int ny = dy[i] + y1;
				if (nx >= 0 && nx < N && ny >= 0 && ny < M && !Visited1[nx][ny]) {
					if (Map[nx][ny] == 0) {
						temp1.push_back({ nx,ny });
						Visited1[nx][ny] = Visited1[x1][y1] + 1;
						que1.push({ nx,ny });
					}
				}
			}
		}
		while (!que2.empty()) {
			x2 = que2.front().first;
			y2 = que2.front().second;
			if (Visited2[x2][y2] == start)break;
			que2.pop();
			if (Map[x2][y2] == 3) continue;
			for (int i = 0; i < 4; i++) {
				int nx = dx[i] + x2;
				int ny = dy[i] + y2;
				if (nx >= 0 && nx < N && ny >= 0 && ny < M && !Visited2[nx][ny]) {
					if (Map[nx][ny] == 0) {
						temp2.push_back({ nx,ny });
						Visited2[nx][ny] = Visited2[x2][y2] + 1;
						que2.push({ nx,ny });
					}
				}
			}
		}
		for (int i = 0; i < temp1.size(); i++)
			Map[temp1[i].first][temp1[i].second] = 1;
		for (int i = 0; i < temp2.size(); i++)
			Map[temp2[i].first][temp2[i].second] = 2;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (Visited1[i][j] != 0 && Visited2[i][j] != 0)
					if (Visited1[i][j] == Visited2[i][j]) Map[i][j] = 3;
			}
		}
		start++;
	}
	while (!que1.empty()) {
		x1 = que1.front().first;
		y1 = que1.front().second;
		que1.pop();
		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + x1;
			int ny = dy[i] + y1;
			if (nx >= 0 && nx < N && ny >= 0 && ny < M && !Visited1[nx][ny]) {
				if (Map[nx][ny] == 0) {
					Map[nx][ny] = 1;
					Visited1[nx][ny] = Visited1[x1][y1] + 1;
					que1.push({ nx,ny });
				}
			}
		}
	}
	while (!que2.empty()) {
		x2 = que2.front().first;
		y2 = que2.front().second;
		que2.pop();
		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + x2;
			int ny = dy[i] + y2;
			if (nx >= 0 && nx < N && ny >= 0 && ny < M && !Visited2[nx][ny]) {
				if (Map[nx][ny] == 0) {
					Map[nx][ny] = 2;
					Visited2[nx][ny] = Visited2[x2][y2] + 1;
					que2.push({ nx,ny });
				}
			}
		}
	}
}
int main() {
	cin >> N >> M;
	int x1, y1, x2, y2;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> Map[i][j];
			if (Map[i][j] == 1) {
				x1 = i; y1 = j;
			}
			else if (Map[i][j] == 2) {
				x2 = i; y2 = j;
			}
		}
	}
	bfs(x1, y1, x2, y2);
	int o_c = 0;
	int t_c = 0;
	int s_c = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (Map[i][j] == 1) o_c++;
			else if (Map[i][j] == 2) t_c++;
			else if (Map[i][j] == 3) s_c++;
		}
	}
	cout << o_c << " " << t_c << " " << s_c << "\n";
}
