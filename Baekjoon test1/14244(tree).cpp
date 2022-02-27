#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	int n, m; cin >> n >> m;
	int k = n - 1;
	int o = n - m; 
	int s = 0, e = 1;
	for (int i = 0; i < k; i++) {
		cout << s << " " << e << "\n";
		if (o != 0) {
			s++;
			e++;
			o--;
		}
		else {
			e++;
		}
	}
}