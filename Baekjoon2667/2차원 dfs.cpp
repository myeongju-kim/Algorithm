#include <iostream> 
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int Map[30][30];
int Visited[30][30];
int N;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int Count = 0;
vector<int> Ans;
void dfs(int x, int y) {
	Visited[x][y] = true;
	Count++;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < N && ny >= 0 && ny < N && !Visited[nx][ny] && Map[nx][ny] == 1) {
			dfs(nx, ny);
		}
	}
}


int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char temp;
			cin >> temp;
			Map[i][j] = temp - '0';
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!Visited[i][j] && Map[i][j] ) {
				dfs(i, j);
				if (Count != 0) Ans.push_back(Count);
				Count = 0;
			}
		}
	}
	sort(Ans.begin(), Ans.end());
	cout << Ans.size() << "\n";
	for (int i = 0; i < Ans.size(); i++)
		cout << Ans[i] << "\n";


	return 0;
}
