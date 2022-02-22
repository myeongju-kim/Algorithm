#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(string a, string b) {
	string temp1, temp2;
	int s1, s2;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] >= 'A' && a[i] <= 'Z') temp1.push_back(a[i] + 32);
		else if (a[i] >= '0' && a[i] <= '9') {
			s1 = i;
			break;
		}
		else temp1.push_back(a[i]);
	}
	for (int i = 0; i < b.size(); i++) {
		if (b[i] >= 'A' && b[i] <= 'Z') temp2.push_back(b[i] + 32);
		else if (b[i] >= '0' && b[i] <= '9') {
			s2 = i;
			break;
		}
		else temp2.push_back(b[i]);
	}
	if (temp1 == temp2) {
		string n1, n2;
		for (int i = s1; i < a.size(); i++) {
			if (a[i] >= '0' && a[i] <= '9') n1.push_back(a[i]);
			else break;
		}
		for (int i = s2; i < b.size(); i++) {
			if (b[i] >= '0' && b[i] <= '9') n2.push_back(b[i]);
			else break;
		}
		int num_a = stoi(n1);
		int num_b = stoi(n2);
		if (num_a == num_b) return false;
		return num_a < num_b;
	}
	return temp1 < temp2;	
}
vector<string> solution(vector<string> files) {
    stable_sort(files.begin(),files.end(),compare);
    return files;
}