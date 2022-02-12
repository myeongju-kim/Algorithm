#include <iostream>
#include <vector>

using namespace std;
int main() {
	string dp[10001];
	int n; cin >> n;
	dp[0] = "0";
	dp[1] = "1";
	for (int i = 2; i <= n; i++) {
		string a = dp[i - 2];
		string b = dp[i - 1];
		string temp;
		int carry = 0;
		int sum = 0;
		while (!a.empty() || !b.empty() || sum ) {
			if (!a.empty()) {
				sum += a.back() - '0';
				a.pop_back();
			}
			if (!b.empty()) {
				sum += b.back() - '0';
				b.pop_back();
			}
			temp.push_back((sum % 10) + '0');
			sum /= 10;
		}
		reverse(temp.begin(), temp.end());
		dp[i] = temp;
	}
	cout << dp[n];
}