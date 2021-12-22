#include <iostream>
#include <vector>
using namespace std;
struct Data {
	bool tr;
};

int main() {
	vector<Data> vec;
	int index = 0, count = 1;
	int doub = 0;
	int n, kim, lim;
	cin >> n >> kim >> lim;
	for (int i = 0; i < n; i++) {
		Data temp;
		if ((i + 1) == kim || (i + 1) == lim) temp.tr = true;
		else temp.tr = false;

		vec.push_back(temp);
	}
	while (n >= 0) {
		if (n % 2 != 0) {
			n++;
			Data temp;
			temp.tr = false;
			vec.push_back(temp);
		}
		if (vec[index].tr == true && vec[index + 1].tr == true) break;
		else if (vec[index + 1].tr == true) {
			vec.erase(vec.begin() + index);
		}
		else{
			vec.erase(vec.begin() + index+1);
		}
		index++;
		doub += 2;
		if (doub >= n) {
			n /= 2;
			count++;
			doub=0;
			index = 0;
		}
	}
	cout << count << endl;


	return 0;
}