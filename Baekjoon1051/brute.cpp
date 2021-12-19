#include <iostream>
using namespace std;

int main(void) {
	int n, m;
	string arr[51];
	int quad[51][51];

	cin >> n;
	cin >> m;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			quad[i][j] = arr[i][j] - '0';

	}
	int col = 0;
	int max = 1;
	int row = 0;

	while (1) {
		for (int i = row + 1; i < n; i++) {
			if (arr[row][col] == arr[i][col]) {
				int k = i - row;
				if (col + k < m) {
					if (arr[row][col] == arr[row][k + col] && arr[i][col] == arr[i][k + col]) {
						if (max < (k + 1) * (k + 1))
							max = (k + 1) * (k + 1);
					}
				}
			}
		}
		row++;

		if (row == n) {
			row = 0;
			col++;
			if (col == m)break;
		}
	}
	cout << max << endl;
	return 0;
}