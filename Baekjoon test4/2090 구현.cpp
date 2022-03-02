#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long gcd(long long a, long long b) {
	if (a % b == 0)return b;
	if (b % a == 0)return a;
	else return gcd(b, a % b);
}

int main() {
	int n;
	cin >> n;
	vector<int> v;
	long long mo = 1;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
		mo *= temp;
	}
	long long ja = 0;
	for (int i = 0; i < v.size(); i++) 
		ja += mo / v[i];
	
	long long g = gcd(mo, ja);
	cout << mo / g << "/" << ja / g << "\n";

}