#include <iostream> 
#include <vector> 
#include <algorithm> 
using namespace std;

static int Mat[51][51];
static int Visited[51][51];
static int N, M;
void Init() {
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			Mat[i][j] = 0;
			Visited[i][j] = 0;
		}
	}
}
void dfs(int x, int y) {
	if (Visited[x][y] == true)
		return;
	if (Mat[x][y] == 0)
		return;
	Visited[x][y] = true;
	dfs(x + 1, y);
	dfs(x - 1, y);
	dfs(x, y + 1);
	dfs(x, y - 1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int bug;
		int count = 0;
		Init();
		cin >> N >> M >> bug;
		for (int i = 0; i < bug; i++) {
			int s, e;
			cin >> s >> e;
			Mat[e][s] = 1;
		}
		for (int i =0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if(Mat[i][j]==1 && !Visited[i][j]){
					count++;
					dfs(i, j);
				}
			}
		}
		cout << count << "\n";
		
	}
	return 0;
}

