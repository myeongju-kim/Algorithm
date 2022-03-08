#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
int Map[51][51];
int Visited[51][51];
int Bord[51][51];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };
void bfs(int x, int y) {
	queue<pair<int, int>>que;
	que.push({ x,y });
	Visited[x][y] = true;
	while (!que.empty()) {
		x = que.front().first;
		y = que.front().second;
		que.pop();
		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + x;
			int ny = dy[i] + y;
			if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
				if (!Visited[nx][ny]) {
					que.push({ nx,ny });
					Visited[nx][ny] = Visited[x][y] + 1;
					if (Map[nx][ny] == 1) Bord[nx][ny] = Visited[nx][ny]-1;
				}
				else if (Visited[nx][ny] > Visited[x][y] + 1) {
					Visited[nx][ny] = Visited[x][y] + 1;
					que.push({ nx,ny });
					if (Map[nx][ny] == 1) Bord[nx][ny] = Visited[nx][ny]-1;
				}
				
			}
		}
	}


}
int main() {
	int k;
	cin >>n>> k;
	vector<pair<int, int>> two_lc;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> Map[i][j];
			if (Map[i][j] == 2) two_lc.push_back({ i,j });
		}
	}
	vector<int> p(two_lc.size(), 0);
	for (int i = 0; i < k; i++)
		p[i] = 1;
	int min = 987654321;
	do {

		for (int i = 0; i < two_lc.size(); i++) {
			if (p[i]) {
				bfs(two_lc[i].first, two_lc[i].second);
			}
		}
		int sum = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				sum += Bord[i][j];
		}
		if (min > sum)
			min = sum;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				Bord[i][j] = 0;
				Visited[i][j] = 0;
			}
		}
	} while (prev_permutation(p.begin(), p.end()));
	cout << min << "\n";

}