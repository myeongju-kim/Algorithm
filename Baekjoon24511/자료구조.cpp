#include <iostream>
#include <vector>
#include <list>
using namespace std;
int main() {
	int n; cin >> n;
	vector<int> sign;
	list<int> lq;
	for (int i = 0; i < n; i++) { int temp; cin >> temp; sign.push_back(temp); }
	for (int i = 0; i < n; i++) {
		int temp; cin >> temp; if(sign[i]==0) lq.push_back(temp);
	}
	int m; cin >> m;
	vector<int> r;
	for (int k = 0; k < m; k++) {
		int In; cin >> In;
		if (lq.size() < m) lq.push_front(In);
	}
	for (int i = 0; i < m; i++) { cout << lq.back()<<" "; lq.pop_back();}
}
