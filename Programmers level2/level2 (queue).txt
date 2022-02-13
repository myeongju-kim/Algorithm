#include <string>
#include <vector>
#include <queue>
using namespace std;
long long gcd(long long a, long long b) {
	if (a % b == 0) return b;
	if (b % a == 0) return a;
	else return gcd(b, a % b);
}
int solution(vector<int> arr) {
    queue<long long> que;
	for (int i = 0; i <arr.size(); i++)
		que.push(arr[i]);
	while (que.size()>1) {
		long long a = que.front(); que.pop();
		long long b = que.front(); que.pop();
		que.push((a * b) / gcd(a, b));
	}
    return que.front();
}