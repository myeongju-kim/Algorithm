#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void samjin(int n) {
	string temp;
	int flag = 0;
	if (n < 0) {
		n *= -1;
		flag = 1;
	}
	while (n!=0) {
		if ((n + 1) % 3 == 0) temp.push_back('T');
		else if (n % 3 == 0) temp.push_back('0');
		else if ((n - 1) % 3 == 0) temp.push_back('1');
		n++;
		n /= 3;
	}
	reverse(temp.begin(), temp.end());
	if (flag == 1) {
		for (int i = 0; i < temp.size(); i++) {
			if (temp[i] == 'T')temp[i] = '1';
			else if (temp[i] == '1')temp[i] = 'T';
		}
	}
	cout << temp;

}
void samjin1(int n) {
	string temp;
	int flag = 0;
	if (n < 0) {
		n *= -1;
		flag = 1;
	}
	while (n != 0) {
		if (n % 3 == 0)temp.push_back('0');
		else temp.push_back((n % 3) + '0');
		n /= 3;
	}
	temp.push_back('0');
	int carry = 0;
	for (int i = 0; i < temp.size()-1; i++) {
		int a = temp[i] - '0';
		if (a >= 2) {
			int ta = a - 3;
			if (ta == -1) temp[i] = 'T';
			else if (ta == 0) temp[i] = '0';
			else if (ta == 1)temp[i] = '1';
			int b = temp[i + 1] - '0' + 1;
			temp[i + 1] = b + '0';
		}
	}
	reverse(temp.begin(), temp.end());
	if (flag == 1) {
		for (int i = 0; i < temp.size(); i++) {
			if (temp[i] == 'T')temp[i] = '1';
			else if (temp[i] == '1')temp[i] = 'T';
		}
	}
	if (temp[0] == '0') temp.erase(temp.begin());
	cout << temp << "\n";
}
int main() {
	int n;
	cin >> n;
	if (n == 0) cout << 0 << "\n";
	else samjin1(n);
}