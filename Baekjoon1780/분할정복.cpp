#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int ma_cnt = 0;
int ze_cnt = 0;
int on_cnt = 0;
int map[3000][3000];

int check(int x, int y, int n) {
	int ok = map[x][y];
	for (int i = x; i < x+n; i++) 
		for (int j = y; j < y+n; j++) 
			if (ok != map[i][j])return 0;

	return 1;
}
void find(int x,int y, int n) {
	int dx[9] = { 0,0,0,n / 3,n / 3,n / 3,n / 3 * 2,n / 3 * 2,n / 3 * 2 };
	int dy[9] = { 0,n / 3,n / 3 * 2,0,n / 3,n / 3 * 2,0,n / 3,n / 3 * 2 };
	if (check(x, y, n) || n==1) {
		if (map[x][y] == -1) ma_cnt++;
		else if (map[x][y] == 0) ze_cnt++;
		else on_cnt++;
		return;
	}
	for (int i = 0; i < 9; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		find(nx, ny, n / 3);
	}
	
}
int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	find(0, 0, n);
	cout << ma_cnt << "\n" << ze_cnt << "\n" << on_cnt <<"\n" ;
	return 0;
}