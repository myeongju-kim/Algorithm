#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int Map[22][22];
int main() {
	//2 -> 
	vector<pair<int, int>> dice{ {2,0},{4,0},{1,0},{3,0},{5,0},{6,0} };
	int N, M, x, y, K;
	cin >> N >> M >> x >> y >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> Map[i][j];
		}
	}
	for (int i = 0; i < K; i++) {
		int wch;
		cin >> wch;
		if (wch == 1) {
			if (y + 1 >= M) continue;
			pair<int, int> b = dice[3];
			dice.erase(dice.begin() + 3);
			dice.insert(dice.begin() + 1, dice.back());
			dice.pop_back();
			dice.push_back(b);
			y++;
			if (Map[x][y] == 0) {
				Map[x][y] = dice[5].second;
			}
			else {
				dice[5].second = Map[x][y];
				Map[x][y] = 0;
			}
			
		}
		else if (wch == 2) {
			if (y - 1 < 0) continue;
			pair<int, int> temp = dice[1];
			dice.erase(dice.begin() + 1);
			dice.push_back(temp);
			temp = dice[3];
			dice[3] = dice[4];
			dice[4] = temp;
			y--;
			if (Map[x][y] == 0) {
				Map[x][y] = dice[5].second;
			}
			else {
				dice[5].second = Map[x][y];
				Map[x][y] = 0;
			}

		}
		else if (wch == 3) {
			if (x - 1 < 0) continue;
			dice.insert(dice.begin(), dice.back());
			dice.pop_back();
			pair<int, int> temp = dice[1];
			dice[1] = dice[2];
			dice[2] = temp;
			temp = dice[3];
			dice[3] = dice[4];
			dice[4] = temp;

			x--;
			if (Map[x][y] == 0) {
				Map[x][y] = dice[5].second;
			}
			else {
				dice[5].second = Map[x][y];
				Map[x][y] = 0;
			}
		}
		else if (wch == 4) {
			if (x + 1 >= N) continue;
			pair<int, int> temp = dice[0];
			dice.erase(dice.begin());
			dice.push_back(temp);
			temp = dice[0];
			dice[0] = dice[1];
			dice[1] = temp;
			temp = dice[2];
			dice[2] = dice[3];
			dice[3] = temp;
			x++;
			if (Map[x][y] == 0) {
				Map[x][y] = dice[5].second;
			}
			else {
				dice[5].second = Map[x][y];
				Map[x][y] = 0;
			}
		}
		cout << dice[2].second << "\n";
	}


}