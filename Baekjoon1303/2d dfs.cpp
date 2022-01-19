#include <iostream> 
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
char mat[150][150];
int visited[150][150];
int N, M;
int attack = 0;
void dfs(int x, int y, char alpa) {
	visited[x][y] = true;
	attack++;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < M && ny >= 0 && ny < N && !visited[nx][ny] && mat[nx][ny] == alpa) {
			dfs(nx, ny, alpa);
		}
	}
}
int main(void) {
	int wsum = 0;
	int bsum = 0;
	cin >> N >> M;
	for (int i = 0; i < M; i++) 
		for (int j = 0; j < N; j++) 
			cin >> mat[i][j];
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				dfs(i, j, mat[i][j]);
				if (mat[i][j] == 'W' || mat[i][j] == 'w')
					wsum += attack * attack;
				else bsum += attack * attack;
				attack = 0;
			}
		}
	}
	cout << wsum << " " << bsum << "\n";
	return 0;
}
