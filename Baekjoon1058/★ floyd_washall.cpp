#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 999999
static int Map[51][51];
static int Visited[51];
static int N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char temp;
			cin >> temp;
			if (temp == 'N') {
				if (i == j)Map[i][i] = 0;
				else {
					Map[i][j] = INF;
					Map[j][i] = INF;
				}
			}
			else {
				Map[i][j] = 1;
				Map[j][i] = 1;
			}
		}
	}
	int max_value = 0;
	for (int k = 0; k < N; k++)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (Map[i][k] + Map[k][j] < Map[i][j])
					Map[i][j] = Map[i][k] + Map[k][j];
	for (int i = 0; i < N; i++) {
		int count = 0;
		for (int j = 0; j < N; j++) {
			if (i == j) continue;
			else if (Map[i][j] <= 2)count++;
		}
		if (max_value < count)
			max_value = count;
	}
	cout << max_value;
	return 0;
}