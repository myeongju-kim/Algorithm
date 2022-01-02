#include <iostream>
#include <queue>
#include <vector>
using namespace std;
char Map[65][65];
int N;

int check_one(int row, int col,int n) {
	for (int i = row; i < n+row; i++) {
		for (int j = col; j < n+col; j++) {
			if (Map[i][j] != '1') return 0;
		}
	}
	return 1;
}
int check_zero(int row, int col, int n) {
	for (int i = row; i < n+row; i++) {
		for (int j = col; j < n+col; j++) {
			if (Map[i][j] != '0') return 0;
		}
	}
	return 1;
}
void Quad_tree(int row, int col, int n) {
	if (check_one(row, col,n)) {
		cout << 1;
		return;
	}
	if (check_zero(row, col, n)) {
		cout << 0;
		return;
	}
	cout << "(";
	Quad_tree(row, col, n / 2);
	Quad_tree(row, col+n/2, n / 2);
	Quad_tree(row+n / 2, col, n / 2);
	Quad_tree(row+n / 2, col+n / 2, n / 2);
	cout << ")";
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char temp;
			cin >> temp;
			Map[i][j] = temp;
		}
	}
	Quad_tree(0,0,N);
	return 0;
}