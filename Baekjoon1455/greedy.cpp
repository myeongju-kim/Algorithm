#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[101][101];
int n, m;
void reverse(int x, int y) {
	for (int i = 0; i <= x; i++) {
		for (int j = 0; j <= y; j++) {
			arr[i][j] = 1 - arr[i][j];
		}
	}
}
int main() {
	int count = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char temp;
			cin >> temp;
			arr[i][j] = temp - '0';
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		for (int j = m - 1; j >= 0; j--) {
			if (arr[i][j] == 1) {
				reverse(i,j);
				count++;
			}
		}
	}
	cout << count << "\n";
	return 0;
}