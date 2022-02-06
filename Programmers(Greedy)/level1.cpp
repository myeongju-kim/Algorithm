#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	vector<int> ans{ 0,0,0,0,0,0,2 };
	int one[5] = { 1,2,3,4,5 };
	int two[8] = { 2,1,2,3,2,4,2,5 };
	int three[10] = { 3,3,1,1,2,2,4,4,5,5 };
	int one_i = 0, two_i = 0, three_i = 0;
	int one_s = 0, two_s = 0, three_s = 0;
	for (int i = 0; i < ans.size(); i++) {
		if (ans[i] == one[one_i++]) one_s++;
		if (ans[i] == two[two_i++]) two_s++;
		if (ans[i] == three[three_i++]) three_s++;
		if (one_i >= 5) one_i = 0;
		if (two_i >= 8) two_i = 0;
		if (three_i >= 10) three_i = 0;
	}
	vector<int> a;
	cout << one_s << " " << two_s << " " << three_s << " ";
	int m = max({ one_s, two_s, three_s });
	if (m == one_s) a.push_back(1);
	if (m == two_s) a.push_back(2);
	if (m == three_s) a.push_back(3);
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << " ";
	return 0;
}