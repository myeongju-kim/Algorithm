#include <iostream>
using namespace std;

int mat[1001][1001] = { 0 };
int dfs_visited[1001] = { 0 };
int N, M;

void Insert_edge(int start, int end) {
	mat[start][end] = 1;
	mat[end][start] = 1;
}
void dfs_mat(int v) {
	dfs_visited[v] = 1;
	//printf("%d -> ", v);
	for (int i = 1; i <= N; i++) {
		if (mat[v][i] == 1 && dfs_visited[i] == 0)
			dfs_mat(i);
	}
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int count = 0;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		Insert_edge(a, b);
	}
	dfs_mat(1);
	count++;
	for (int i = 1; i <= N; i++) {
		if (!dfs_visited[i]) {
			dfs_mat(i);
			count++;
			i = 1;
		}
	}
	cout << count;
	return 0;
}