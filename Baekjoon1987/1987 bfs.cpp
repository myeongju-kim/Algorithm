#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;
int N, M;
char Map[21][21];
int Visited[21][21];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int Max = 0;
map<char, int> Alpa;

void dfs(int x,int y, int go){
	Visited[x][y] = go + 1;
	if (Max < Visited[x][y]) Max = Visited[x][y];
	Alpa[Map[x][y]] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = dx[i] + x;
		int ny = dy[i] + y;
		if (nx >= 0 && nx < N && ny >= 0 && ny < M && !Visited[nx][ny]) {
			if (Alpa[Map[nx][ny]]==0) {
				dfs(nx, ny, Visited[x][y]);
			}
		}
	}
	Alpa[Map[x][y]] = 0;
	Visited[x][y] = 0;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < M; j++) 
			cin >> Map[i][j];
	dfs(0, 0, 0);
	cout << Max << "\n";
}