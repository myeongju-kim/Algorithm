#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int check(string pel) {
	string temp = pel;
	reverse(temp.begin(), temp.end());
	if (pel == temp)return true;
	return false;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string pel;
	cin >> pel;
	int n = pel.size();
	int f = 0;
	string temp = pel;
	while (1) {
		if (check(pel))break;
		pel = temp;
		for (int i = f; i >= 0; i--) {
			pel += pel[i];
		}
		f++;
	}
	cout << pel.size()<< "\n";
	return 0;
}