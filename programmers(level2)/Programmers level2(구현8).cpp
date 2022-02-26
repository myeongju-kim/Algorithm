#include <string>
#include <vector>

using namespace std;
int dx[3] = { 0,1,1 };
int dy[3] = { 1,0,1 };
int visited[100][100];
int Cnt(int m, int n) {
	int c = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (visited[i][j] == 1) c++;
	return c;
}
int solution(int m, int n, vector<string> b) {
    int total=0;
    while (1) {
		int flag = 0;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++) visited[i][j] = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				char a = b[i][j];
				if (a == '*')continue;
				int cnt = 1;
				for (int k = 0; k < 3; k++) {
					int nx = dx[k] + i;
					int ny = dy[k] + j;
					if (nx >= 0 && nx < m && ny >= 0 && ny < n && b[nx][ny] == a) cnt++;
					else break;
				}
				if (cnt == 4) {
					visited[i][j] = 1;
					flag = 1;
					for (int k = 0; k < 3; k++) {
						int nx = dx[k] + i;
						int ny = dy[k] + j;
						visited[nx][ny] = 1;
					}
				}
			}
		}
		if (flag == 0)break;
		total += Cnt(m,n);

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (visited[i][j] == 1) b[i][j] = '*';
			}
		}
		vector<char> arr[100];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (b[j][i] != '*') {
					arr[i].push_back(b[j][i]);
					b[j][i] = '*';
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = m - 1; j >= 0; j--) {
				if (b[j][i] == '*') {
					if (arr[i].empty())break;
					b[j][i] = arr[i].back();
					arr[i].erase(--arr[i].end());
				}
			}
		}
	}
    return total;
}