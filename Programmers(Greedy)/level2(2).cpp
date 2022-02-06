#include <string>
#include <vector>
#include <set>
using namespace std;

char t[2];
int visited[20];
set<int> number;
void dfs(int n, int len, int size, string a) {
	if (size == len) {
		string temp="";
		for (int i = 0; i < size; i++)
			temp += t[i];
		number.insert(stoi(temp));
		return;
	}
	for (int i = 0; i < a.size(); i++) {
		if (!visited[i]) {
			t[n] = a[i];
			visited[i] = true;
			dfs(n + 1, len, size + 1, a);
			visited[i] = false;
		}
	}
}
int check(int n) {
	if (n <= 1)return 0;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (n % i == 0)cnt++;
		if (cnt >= 3)return 0;
	}
	return 1;
	
}
int solution(string numbers) {
    int answer = 0;
    for (int i = 1; i <= numbers.size(); i++)
		dfs(0, i, 0,numbers);
    for (auto iter = number.begin(); iter != number.end(); iter++) {
		if (check(*iter)) answer++;
	}
    return answer;
}